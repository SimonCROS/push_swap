#include "libft.h"

ssize_t	ft_puthex_fd(unsigned char c, int fd)
{
	if (c > 9)
		return (ft_putchar_fd('a' + c - 10, fd));
	return (ft_putchar_fd('0' + c, fd));
}

ssize_t	ft_puthex(unsigned char c)
{
	return (ft_puthex_fd(c, 1));
}
