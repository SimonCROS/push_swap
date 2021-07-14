#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*pointer;
	size_t	size;
	int		i;

	if (!s)
		return (NULL);
	size = ft_strlen(s) + 1;
	pointer = malloc(size);
	if (!pointer)
		return (NULL);
	i = 0;
	while (s[i])
	{
		pointer[i] = f(i, s[i]);
		i++;
	}
	pointer[i] = 0;
	return (pointer);
}
