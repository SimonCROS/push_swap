#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	cur;

	while (n)
	{
		if (n >= sizeof(long))
		{
			cur = sizeof(long);
			*((long *)s) = 0;
		}
		else
		{
			cur = 1;
			*((char *)s) = 0;
		}
		s += cur;
		n -= cur;
	}
}
