int	ft_atof_full(char *str, float *result)
{
	int		dot;
	float	ret;
	float	mul;

	ret = 0;
	mul = 1;
	dot = 0;
	if (*str == '-' && str++)
		mul = -1;
	while ((*str >= '0' && *str <= '9') || (*str == '.' && !dot))
	{
		if (dot)
			dot++;
		if (*str == '.')
			dot = 1;
		else
		{
			if (dot)
				mul /= 10.0f;
			ret = ret * 10.0f + (float)(*str - '0');
		}
		str++;
	}
	*result = ret * mul;
	return (!(*str) && dot != 1);
}

float	ft_atof(char *str)
{
	int		dot;
	float	ret;
	float	mul;

	ret = 0;
	mul = 1;
	dot = 0;
	if (*str == '-')
	{
		str++;
		mul = -1;
	}
	while ((*str >= '0' && *str <= '9') || (*str == '.' && !dot))
	{
		if (*str == '.')
			dot = 1;
		else
		{
			if (dot)
				mul /= 10.0f;
			ret = ret * 10.0f + (float)(*str - '0');
		}
		str++;
	}
	return (ret * mul);
}
