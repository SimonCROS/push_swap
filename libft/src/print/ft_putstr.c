#include "libft.h"

ssize_t	ft_putstr_fd(char *s, int fd)
{
	if (s)
		return (write(fd, s, ft_strlen(s)));
	return (0);
}

ssize_t	ft_putstr(char *s)
{
	return (ft_putstr_fd(s, 1));
}
