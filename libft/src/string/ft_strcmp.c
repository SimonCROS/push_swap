#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (-1);
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	return (*s1 - *s2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		ret;

	ret = 0;
	i = 0;
	while (n-- && ((unsigned char)s1[i] || (unsigned char)s2[i]) && !ret)
	{
		ret = ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (ret);
}

int	ft_starts_with(char *string, char *prefix)
{
	if (!string || !prefix)
		return (FALSE);
	while (*prefix)
	{
		if (*string != *prefix)
			return (FALSE);
		string++;
		prefix++;
	}
	return (TRUE);
}

int	ft_ends_with(char *string, char *suffix)
{
	size_t	string_len;
	size_t	suffix_len;

	if (!string || !suffix)
		return (FALSE);
	string_len = ft_strlen(string);
	suffix_len = ft_strlen(suffix);
	if (string_len < suffix_len)
		return (FALSE);
	return (ft_str_equals(string + string_len - suffix_len, suffix));
}

int	ft_str_equals(char *s1, char *s2)
{
	return (s1 == s2 || ft_strcmp(s1, s2) == 0);
}
