#include "libft.h"

t_map	*map_copy(t_map *original)
{
	t_map			*copy;
	t_citerator		iter;
	t_mapentry		*elem;

	copy = map_new(original->identity_checker, original->del);
	iter = citerator_new((const t_clist *)original);
	while (citerator_has_next(&iter))
	{
		elem = citerator_next(&iter);
		map_put(copy, elem->key, elem->value);
	}
	return (copy);
}

t_map	*map_clone(t_map *original, t_function copy_elem)
{
	t_map			*copy;
	t_citerator		iter;
	t_mapentry		*elem;

	copy = map_new(original->identity_checker, original->del);
	iter = citerator_new((const t_clist *)original);
	while (citerator_has_next(&iter))
	{
		elem = citerator_next(&iter);
		map_put(copy, copy_elem(elem->key), copy_elem(elem->value));
	}
	return (copy);
}
