#include "libft.h"
#include <math.h>

void	bmp_set_pixel(t_bitmap *bitmap, int x, int y, t_color color)
{
	t_bmpinfoheader	*inf;
	int				pos;

	inf = &(bitmap->header.infos);
	pos = ((inf->height - y - 1) * inf->width + x) * (inf->bitsperpixel / 8);
	bitmap->body[pos] = (char)(fminf(color.b, 1) * 255);
	bitmap->body[pos + 1] = (char)(fminf(color.g, 1) * 255);
	bitmap->body[pos + 2] = (char)(fminf(color.r, 1) * 255);
	bitmap->body[pos + 3] = 0x0;
}

t_color	bmp_get_pixel(t_bitmap *bitmap, int x, int y)
{
	t_bmpinfoheader	*inf;
	int				pos;

	inf = &(bitmap->header.infos);
	pos = ((inf->height - y - 1) * inf->width + x) * (inf->bitsperpixel / 8);
	return (color_new(bitmap->body[pos + 2], bitmap->body[pos + 1],
			bitmap->body[pos]));
}
