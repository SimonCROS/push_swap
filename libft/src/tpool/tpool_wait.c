#include "tpool.h"

void	tpool_wait(t_tpool *pool)
{
	if (pool == NULL)
		return ;
	pthread_mutex_lock(&(pool->work_mutex));
	while (1)
	{
		if ((!pool->stop && pool->working_cnt != 0)
			|| (pool->stop && pool->thread_cnt != 0)
			|| (!pool->stop && pool->works->size))
			pthread_cond_wait(&(pool->working_cond), &(pool->work_mutex));
		else
			break ;
	}
	pthread_mutex_unlock(&(pool->work_mutex));
	pool->stop = 1;
}
