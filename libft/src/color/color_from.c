#include "libft.h"

t_color	color_new(t_uint8 r, t_uint8 g, t_uint8 b)
{
	return (color_newa(r, g, b, 255));
}

t_color	color_from_hex(t_uint32 hex)
{
	return (color_from_hexa(0x00ffffff & hex));
}

t_color	color_from_hsl(float h, float s, float l)
{
	return (color_from_hsla(h, s, l, 1));
}
