#ifndef TPOOL_H
# define TPOOL_H

# include <pthread.h>
# include "libft.h"

typedef struct s_tpool_work
{
	struct s_tpool_work	*next;
	t_bifunction		func;
	void				*arg1;
	void				*arg2;
}	t_tpool_work;

typedef struct s_tpool
{
	t_clist			*works;
	pthread_mutex_t	work_mutex;
	pthread_cond_t	work_cond;
	pthread_cond_t	working_cond;
	size_t			working_cnt;
	size_t			thread_cnt;
	size_t			size;
	int				stop;
	char			*name;
}	t_tpool;

int		tpool_add_work(t_tpool *pool, t_bifunction func, void *ar1, void *ar2);
t_tpool	*tpool_new(size_t max_thread);
void	tpool_destroy(t_tpool *pool);
int		tpool_start(t_tpool *pool);
void	tpool_free(t_tpool *pool);
void	tpool_wait(t_tpool *pool);
void	tpool_set_name(t_tpool *pool, char *name);
int		pthread_setname_ft(char *name);
int		pthread_getname_ft(char *name, size_t buffer_len);

#endif
