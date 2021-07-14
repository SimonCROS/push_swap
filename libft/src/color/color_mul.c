#include "libft.h"

static t_color	operation(const t_color v, float r, float g, float b)
{
	t_color	vec;

	vec.r = v.r * r;
	vec.g = v.g * g;
	vec.b = v.b * b;
	vec.a = 1;
	return (vec);
}

t_color	color_mulf(const t_color v, float a)
{
	return (operation(v, a, a, a));
}

t_color	color_mul(const t_color v1, const t_color v2)
{
	return (operation(v1, v2.r, v2.g, v2.b));
}
