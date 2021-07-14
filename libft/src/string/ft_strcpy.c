#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	while (i < dstsize - 1 && src[i])
	{
		if (dstsize > 0)
			dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = 0;
	while (src[i])
		i++;
	return (i);
}
