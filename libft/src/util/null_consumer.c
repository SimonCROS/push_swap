#include "libft.h"

static void	null_consumer_funct(void *a)
{
	(void)a;
}

static void	null_biconsumer_funct(void *a, void *b)
{
	(void)a;
	(void)b;
}

t_consumer	null_consumer(void)
{
	return (&null_consumer_funct);
}

t_biconsumer	null_biconsumer(void)
{
	return (&null_biconsumer_funct);
}
