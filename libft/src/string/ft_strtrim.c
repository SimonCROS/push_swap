#include "libft.h"

static int	ft_contains(char needle, const char *haystack)
{
	size_t	i;

	i = 0;
	while (haystack[i])
		if (needle == haystack[i++])
			return (1);
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	from;
	size_t	to;

	if (!s1)
		return (NULL);
	from = 0;
	to = ft_strlen(s1) - 1;
	while (from <= to && ft_contains(s1[from], set))
		++from;
	while (to > from && ft_contains(s1[to], set))
		--to;
	str = malloc(to - from + 2);
	if (!str)
		return (NULL);
	ft_memcpy(str, &(s1[from]), to - from + 1);
	str[to - from + 1] = 0;
	return (str);
}
