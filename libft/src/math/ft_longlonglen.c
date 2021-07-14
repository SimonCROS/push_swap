#include "libft.h"

int	ft_longlonglen(long long n)
{
	if (n < 0 && n - 1 > 0)
		return (20);
	if (n < 0)
		return (1 + ft_longlonglen(-n));
	if (n < 10)
		return (1);
	return (1 + ft_longlonglen(n / 10));
}

int	ft_ulonglonglen(unsigned long long n)
{
	if (n < 10)
		return (1);
	return (1 + ft_ulonglonglen(n / 10));
}

int	ft_longlonglen_hex(unsigned long long n, int pre, int width)
{
	if (width)
		return (fmaxi(width + (!!pre * 2), ft_longlonglen_hex(n / 16, 0, 0)));
	if (pre)
		return (3 + ft_longlonglen_hex(n / 16, 0, 0));
	if (n < 16)
		return (1);
	return (1 + ft_longlonglen_hex(n / 16, 0, 0));
}

int	ft_longlonglen_octal(unsigned long long n)
{
	if (n < 8)
		return (1);
	return (1 + ft_longlonglen_octal(n / 8));
}
