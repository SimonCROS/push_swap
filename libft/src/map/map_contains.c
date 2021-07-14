#include "libft.h"

int	map_contains_key(t_map *map, void *key)
{
	t_mapentry	*entry;

	if (clst_is_empty((t_clist *)map))
		return (FALSE);
	entry = map->first;
	while (entry)
	{
		if (map->identity_checker(entry->key, key))
			return (TRUE);
		entry = entry->next;
	}
	return (FALSE);
}
