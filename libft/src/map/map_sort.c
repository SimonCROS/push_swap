#include "libft.h"

static void	map_swap(t_mapentry *arg1, t_mapentry *arg2)
{
	t_mapentry	temp;

	temp.key = arg1->key;
	temp.value = arg1->value;
	arg1->key = arg2->key;
	arg1->value = arg2->value;
	arg2->key = temp.key;
	arg2->value = temp.value;
}

t_map	*map_sort(t_map *map, t_comparator comparator)
{
	t_map			*sorted_map;
	t_citerator		iter1;
	t_citerator		iter2;
	t_mapentry		*curr;
	t_mapentry		*elem;

	sorted_map = map_copy(map);
	iter1 = citerator_new((const t_clist *)sorted_map);
	while (citerator_has_next(&iter1))
	{
		curr = citerator_next(&iter1);
		iter2 = citerator_new((const t_clist *)sorted_map);
		while (citerator_has_next(&iter2))
		{
			elem = citerator_next(&iter2);
			if (comparator(curr->key, elem->key) < 0)
				map_swap(curr, elem);
		}
	}
	return (sorted_map);
}
