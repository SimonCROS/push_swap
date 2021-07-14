#include "libft.h"

static size_t	min(size_t t1, size_t t2)
{
	if (t1 < t2)
		return (t1);
	return (t2);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	len = min(len, ft_strlen(s));
	if (start >= ft_strlen(s))
		len = 0;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, len);
	str[len] = 0;
	return (str);
}
