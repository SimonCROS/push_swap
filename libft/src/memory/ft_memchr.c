#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cp;

	cp = (unsigned char *)s;
	c = (unsigned char)c;
	while (n--)
	{
		if (*cp == c)
			return (cp);
		++cp;
	}
	return (NULL);
}
