int	str_is_empty(char *str)
{
	return (!str || !str[0]);
}

int	str_not_empty(char *str)
{
	return (str && str[0]);
}
