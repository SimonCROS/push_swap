#include "libft.h"

t_list	*lst_map(t_list *list, t_function mapper, t_consumer del)
{
	t_entry	*entry;
	t_list	*copy;

	copy = lst_new(del);
	if (!copy)
		return (NULL);
	if (lst_is_empty(list))
		return (copy);
	entry = list->first;
	lst_push(copy, mapper(entry->value));
	while (entry->next)
	{
		entry = entry->next;
		lst_push(copy, mapper(entry->value));
	}
	return (copy);
}

t_list	*lst_map_in(t_list *list, t_function mapper, t_consumer del)
{
	t_entry	*entry;

	list->del = del;
	if (lst_is_empty(list))
		return (list);
	entry = list->first;
	entry->value = mapper(entry->value);
	while (entry->next)
	{
		entry = entry->next;
		entry->value = mapper(entry->value);
	}
	return (list);
}
