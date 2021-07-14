#ifndef TPOOL_PRIVATE_H
# define TPOOL_PRIVATE_H

# include "tpool.h"

typedef struct s_tpool_thread
{
	int			id;
	pthread_t	thread;
	t_tpool		*pool;
}	t_tpool_thread;

#endif
