#include "libft.h"

ssize_t	ft_putnbr_fd(long n, int fd)
{
	if (n < 0)
		return (ft_putchar_fd('-', fd) + ft_putchar_fd(-n, fd));
	if (n < 10)
		return (ft_putchar_fd(n + '0', fd));
	return (ft_putnbr_fd(n / 10, fd) + ft_putnbr_fd(n % 10, fd));
}

ssize_t	ft_putnbr(long n)
{
	return (ft_putnbr_fd(n, 1));
}
