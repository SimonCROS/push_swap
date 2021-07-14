int	ft_strindex_of(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		if (str[i++] == c)
			return (i - 1);
	return (-1);
}
