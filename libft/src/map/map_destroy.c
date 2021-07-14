#include "libft.h"

void	map_free(t_map *map)
{
	t_mapentry	*entry;
	t_mapentry	*next;

	if (clst_is_empty((t_clist *)map))
		return ;
	entry = map->first;
	while (entry)
	{
		next = entry->next;
		free(entry);
		--(map->size);
		entry = next;
	}
	free(map);
}

void	map_clear(t_map *map)
{
	t_mapentry	*entry;
	t_mapentry	*next;

	if (clst_is_empty((t_clist *)map))
		return ;
	entry = map->first;
	while (entry)
	{
		next = entry->next;
		map->del(entry->key, entry->value);
		free(entry);
		--(map->size);
		entry = next;
	}
}

void	map_destroy(t_map *map)
{
	if (map)
	{
		map_clear(map);
		free(map);
	}
}
