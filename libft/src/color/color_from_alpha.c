#include "libft.h"

t_color	color_newa(t_uint8 r, t_uint8 g, t_uint8 b
	, t_uint8 a)
{
	t_color	color;

	color.r = r / (float)255;
	color.g = g / (float)255;
	color.b = b / (float)255;
	color.a = a / (float)255;
	return (color);
}

t_color	color_from_hexa(t_uint32 hex)
{
	t_color	color;

	color.a = (255 - (t_uint8)(hex >> 24)) / (float)255;
	color.r = (t_uint8)(hex >> 16) / (float)255;
	color.g = (t_uint8)(hex >> 8) / (float)255;
	color.b = (t_uint8)(hex) / (float)255;
	return (color);
}

static float	hue2rgb(float p, float q, float t)
{
	if (t < 0)
		t += 1;
	if (t > 1)
		t -= 1;
	if (t < 1 / 6.)
		return (p + (q - p) * 6 * t);
	if (t < 1 / 2.)
		return (q);
	if (t < 2 / 3.)
		return (p + (q - p) * (2 / 3. - t) * 6);
	return (p);
}

t_color	color_from_hsla(float h, float s, float l, float a)
{
	t_color	color;
	float	q;
	float	p;

	if (s == 0)
	{
		color.r = l;
		color.g = l;
		color.b = l;
	}
	else
	{
		if (l < 0.5)
			q = l * (1 + s);
		else
			q = l + s - l * s;
		p = 2 * l - q;
		color.r = hue2rgb(p, q, h + 1 / 3.);
		color.g = hue2rgb(p, q, h);
		color.b = hue2rgb(p, q, h - 1 / 3.);
	}
	color.a = a;
	return (color);
}
