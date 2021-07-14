#include "libft.h"

char	**str_rmlast(char **container)
{
	char	*res;
	int		len;
	int		i;

	if (!container)
		return (NULL);
	len = ft_strlen(*container);
	if (len > 0)
	{
		res = malloc(len);
		if (!res)
			return (NULL);
		i = -1;
		while (++i < len - 1)
			res[i] = (*container)[i];
		res[i] = 0;
		free(*container);
		*container = res;
	}
	return (container);
}
