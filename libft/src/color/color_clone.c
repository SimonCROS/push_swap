#include "libft.h"

t_color	*color_clone(const t_color c)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	*color = color_copy(c);
	return (color);
}

t_color	color_copy(const t_color c)
{
	t_color	color;

	color.r = c.r;
	color.g = c.g;
	color.b = c.b;
	color.a = c.a;
	return (color);
}
