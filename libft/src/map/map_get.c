#include "libft.h"

void	*map_get(t_map *map, void *key)
{
	t_mapentry	*entry;

	if (clst_is_empty((t_clist *)map))
		return (NULL);
	entry = map->first;
	while (entry)
	{
		if (map->identity_checker(entry->key, key))
			return (entry->value);
		entry = entry->next;
	}
	return (NULL);
}
