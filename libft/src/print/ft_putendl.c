#include "libft.h"

ssize_t	ft_putendl_fd(char *s, int fd)
{
	return (ft_putstr_fd(s, fd) + ft_putchar_fd('\n', fd));
}

ssize_t	ft_putendl(char *s)
{
	return (ft_putendl_fd(s, 1));
}
