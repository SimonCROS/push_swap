#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*sstr;
	unsigned char	*dstr;

	i = 0;
	sstr = (unsigned char *)src;
	dstr = dst;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		dstr[i] = sstr[i];
		++i;
	}
	return (dst);
}
