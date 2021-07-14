#include "libft.h"

void	*lst_remove(t_list *list, int index)
{
	t_entry	**parent_next;
	t_entry	*entry;
	void	*value;

	if (lst_is_empty(list) || index < 0 || index >= list->size)
		return (NULL);
	parent_next = &(list->first);
	entry = list->first;
	while (index--)
	{
		parent_next = &(entry->next);
		entry = entry->next;
	}
	*parent_next = entry->next;
	value = entry->value;
	free(entry);
	--(list->size);
	return (value);
}
