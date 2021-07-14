#include "libft.h"
#include <math.h>

unsigned int	color_to_hexa(const t_color c)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;

	r = fminf(c.r, 1) * 255;
	g = fminf(c.g, 1) * 255;
	b = fminf(c.b, 1) * 255;
	a = 255 - (fminf(c.a, 1) * 255);
	return (a << 24 | r << 16 | g << 8 | b);
}

unsigned int	color_to_hex(const t_color c)
{
	return (0x00ffffff & color_to_hexa(c));
}
