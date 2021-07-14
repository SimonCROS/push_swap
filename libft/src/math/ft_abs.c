#include "libft.h"

long	ft_abs(long number)
{
	if (number < 0)
		return (-number);
	return (number);
}

double	ft_fabs(double number)
{
	if (number < 0)
		return (-number);
	return (number);
}
