#include "tpool.h"

int	tpool_add_work(t_tpool *pool, t_bifunction func, void *arg1, void *arg2)
{
	t_tpool_work	*entry;

	if (!pool)
		return (FALSE);
	entry = malloc(sizeof(t_tpool_work));
	if (!entry)
		return (FALSE);
	entry->next = NULL;
	entry->func = func;
	entry->arg1 = arg1;
	entry->arg2 = arg2;
	pthread_mutex_lock(&(pool->work_mutex));
	clst_push(pool->works, entry);
	pthread_cond_broadcast(&(pool->work_cond));
	pthread_mutex_unlock(&(pool->work_mutex));
	return (TRUE);
}
