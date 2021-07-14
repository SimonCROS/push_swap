#include "private/tpool_private.h"
#include "tpool.h"

static int	worker_loop(t_tpool *pool)
{
	t_tpool_work	*work;

	pthread_mutex_lock(&(pool->work_mutex));
	while (clst_is_empty(pool->works) && !pool->stop)
		pthread_cond_wait(&(pool->work_cond), &(pool->work_mutex));
	if (pool->stop)
		return (FALSE);
	work = clst_shift(pool->works);
	pool->working_cnt++;
	pthread_mutex_unlock(&(pool->work_mutex));
	if (work != NULL)
	{
		work->func(work->arg1, work->arg2);
		pool->works->del(work);
	}
	pthread_mutex_lock(&(pool->work_mutex));
	pool->working_cnt--;
	if (!pool->stop && pool->working_cnt == 0 && clst_is_empty(pool->works))
		pthread_cond_signal(&(pool->working_cond));
	pthread_mutex_unlock(&(pool->work_mutex));
	return (TRUE);
}

static void	compute_name(t_tpool_thread *thread)
{
	char	*tmp;
	char	*name;

	tmp = ft_itoa(thread->id * -1);
	if (thread->pool->name)
		name = ft_strjoin(thread->pool->name, tmp);
	else
		name = ft_strjoin("POOL", tmp);
	pthread_setname_ft(name);
	free(tmp);
	free(name);
}

static void	*tpool_worker(void *arg)
{
	t_tpool_thread	*thread;
	t_tpool			*pool;

	thread = arg;
	pool = thread->pool;
	compute_name(thread);
	free(arg);
	while (1)
	{
		if (!worker_loop(pool))
			break ;
	}
	pool->thread_cnt--;
	pthread_cond_signal(&(pool->working_cond));
	pthread_mutex_unlock(&(pool->work_mutex));
	return (NULL);
}

int	tpool_start(t_tpool *pool)
{
	t_tpool_thread	*thread;
	size_t			i;

	i = 0;
	pool->stop = 0;
	while (i++ < pool->size)
	{
		thread = malloc(sizeof(t_tpool_thread));
		if (!thread)
		{
			tpool_destroy(pool);
			return (FALSE);
		}
		thread->id = i;
		thread->pool = pool;
		if (pthread_create(&thread->thread, NULL, tpool_worker, thread))
		{
			free(thread);
			tpool_destroy(pool);
			return (FALSE);
		}
		pthread_detach(thread->thread);
		pool->thread_cnt++;
	}
	return (TRUE);
}

t_tpool	*tpool_new(size_t num)
{
	t_tpool		*pool;

	if (num == 0)
		num = 1;
	pool = ft_calloc(1, sizeof(*pool));
	pool->size = num;
	pthread_mutex_init(&(pool->work_mutex), NULL);
	pthread_cond_init(&(pool->work_cond), NULL);
	pthread_cond_init(&(pool->working_cond), NULL);
	pool->works = clst_new(free);
	pool->name = NULL;
	return (pool);
}
