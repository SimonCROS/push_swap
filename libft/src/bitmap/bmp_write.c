#include "libft.h"
#include <fcntl.h>

int	bmp_save(char *output, t_bitmap *bitmap)
{
	int	fd;

	fd = open(output, O_TRUNC | O_WRONLY | O_CREAT, 0777);
	if (fd == -1)
		return (0);
	bmp_write(fd, bitmap);
	close(fd);
	return (1);
}

ssize_t	bmp_write(int fd, t_bitmap *bitmap)
{
	if (write(fd, &(bitmap->header.file), sizeof(t_bmpheader)) == -1)
		return (0);
	if (write(fd, bitmap->body, bitmap->header.infos.imagesize) == -1)
		return (0);
	return (1);
}
