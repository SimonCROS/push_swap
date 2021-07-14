#include "libft.h"

ssize_t	ft_putchar_fd(char c, int fd)
{
	if (c)
		return (write(fd, &c, 1));
	return (0);
}

ssize_t	ft_putchar(char c)
{
	return (ft_putchar_fd(c, 1));
}
