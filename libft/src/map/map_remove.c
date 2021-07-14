#include "libft.h"

void	*map_remove(t_map *map, void *key)
{
	t_mapentry	**parent_next;
	t_mapentry	*entry;
	void		*value;

	if (clst_is_empty((t_clist *)map))
		return (NULL);
	parent_next = &(map->first);
	entry = map->first;
	while (entry && !map->identity_checker(entry->key, key))
	{
		parent_next = &(entry->next);
		entry = entry->next;
	}
	if (entry)
	{
		*parent_next = entry->next;
		value = entry->value;
		map->del(entry->key, NULL);
		free(entry);
		--(map->size);
		return (value);
	}
	return (NULL);
}

int	map_delete(t_map *map, void *key)
{
	t_mapentry	**parent_next;
	t_mapentry	*entry;

	if (clst_is_empty((t_clist *)map))
		return (FALSE);
	parent_next = &(map->first);
	entry = map->first;
	while (entry && !map->identity_checker(entry->key, key))
	{
		parent_next = &(entry->next);
		entry = entry->next;
	}
	if (entry)
	{
		*parent_next = entry->next;
		map->del(entry->key, entry->value);
		free(entry);
		--(map->size);
		return (TRUE);
	}
	return (FALSE);
}
