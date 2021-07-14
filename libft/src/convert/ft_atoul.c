int	ft_atoul_full(char *str, unsigned long *result)
{
	unsigned long	ret;

	ret = 0;
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	*result = ret;
	return (!(*str));
}

unsigned long	ft_atoul(char *str)
{
	unsigned long	ret;

	ret = 0;
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (ret);
}
