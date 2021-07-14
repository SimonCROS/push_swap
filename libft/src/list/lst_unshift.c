#include "libft.h"

void	*lst_unshift(t_list *list, void *element)
{
	t_entry	*entry;

	entry = lst_new_entry(element);
	if (!entry)
	{
		list->del(element);
		return (NULL);
	}
	entry->next = list->first;
	list->first = entry;
	++(list->size);
	return (element);
}
