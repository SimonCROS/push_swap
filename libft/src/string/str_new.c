#include "libft.h"

char	**as_string(char *str)
{
	char	**string;

	if (!str)
		return (NULL);
	string = malloc(sizeof(char *));
	if (!string)
		return (NULL);
	*string = ft_strdup(str);
	if (!*string)
	{
		free(string);
		return (NULL);
	}
	return (string);
}

char	**str_new(void)
{
	return (as_string(""));
}
