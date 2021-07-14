#include "libft.h"

static int	is_uchar(char *str)
{
	int	ret;

	ret = 0;
	while (*str >= '0' && *str <= '9')
		ret = ret * 10 + (*(str++) - '0');
	return (!(*str) && ret < 256);
}

static int	ft_atouc_full(char *str, unsigned char *result)
{
	unsigned char	ret;

	if (!is_uchar(str))
		return (0);
	ret = 0;
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	*result = ret;
	return (!(*str));
}

int	color_deserialize(const char *str, t_color *color)
{
	t_list			*parts;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				ret;

	if (ft_strcnt(str, ',') != 2)
		return (0);
	ret = 0;
	parts = as_listf((void **)ft_split(str, ','), &free);
	if (parts->size == 3)
	{
		if (ft_atouc_full(lst_get(parts, 0), &r)
			&& ft_atouc_full(lst_get(parts, 1), &g)
			&& ft_atouc_full(lst_get(parts, 2), &b))
		{
			ret = 1;
			*color = color_new(r, g, b);
		}
	}
	lst_destroy(parts);
	return (ret);
}
