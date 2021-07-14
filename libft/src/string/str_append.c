#include "libft.h"

char	**str_append(char **container, char *str)
{
	char	*tmp;

	if (!container)
		return (NULL);
	if (!str)
		return (container);
	tmp = *container;
	*container = ft_strjoin(tmp, str);
	free(tmp);
	if (!*container)
		return (NULL);
	return (container);
}

char	**str_cappend(char **container, char c)
{
	char	*tmp;
	char	char_to_str[2];

	if (!container)
		return (NULL);
	tmp = *container;
	char_to_str[0] = c;
	char_to_str[1] = 0;
	*container = ft_strjoin(tmp, char_to_str);
	free(tmp);
	if (!*container)
		return (NULL);
	return (container);
}

char	**str_prepend(char **container, char *str)
{
	char	*tmp;

	if (!container)
		return (NULL);
	if (!str)
		return (container);
	tmp = *container;
	*container = ft_strjoin(str, tmp);
	free(tmp);
	if (!*container)
		return (NULL);
	return (container);
}
