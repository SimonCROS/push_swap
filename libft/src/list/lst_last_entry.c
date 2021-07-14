#include "libft.h"

t_centry	*clst_last_entry(t_clist *list)
{
	t_centry	*entry;

	if (clst_is_empty(list))
		return (NULL);
	entry = list->first;
	while (entry->next)
		entry = entry->next;
	return (entry);
}

t_entry	*lst_last_entry(t_list *list)
{
	t_entry	*entry;

	if (lst_is_empty(list))
		return (NULL);
	entry = list->first;
	while (entry->next)
		entry = entry->next;
	return (entry);
}
