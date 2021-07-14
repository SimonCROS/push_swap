#include "tpool.h"

void	tpool_free(t_tpool *pool)
{
	if (!pool)
		return ;
	clst_destroy(pool->works);
	free(pool);
}

void	tpool_destroy(t_tpool *pool)
{
	if (!pool)
		return ;
	pthread_mutex_lock(&(pool->work_mutex));
	pool->stop = 1;
	pthread_cond_broadcast(&(pool->work_cond));
	pthread_mutex_unlock(&(pool->work_mutex));
	tpool_wait(pool);
	pthread_mutex_destroy(&(pool->work_mutex));
	pthread_cond_destroy(&(pool->work_cond));
	pthread_cond_destroy(&(pool->working_cond));
	tpool_free(pool);
}
