#include "libft.h"

t_list	*as_list(void **array, t_consumer del)
{
	t_list	*list;
	t_entry	**prev;
	t_entry	*entry;

	if (!array)
		return (NULL);
	list = lst_new(del);
	if (!list)
		return (NULL);
	prev = &list->first;
	while (*array)
	{
		entry = lst_new_entry(*array);
		if (!entry)
		{
			lst_free(list);
			return (NULL);
		}
		*prev = entry;
		prev = &entry->next;
		list->size++;
		array++;
	}
	return (list);
}

t_list	*as_listf(void **array, t_consumer del)
{
	t_list	*list;

	if (!array)
		return (NULL);
	list = as_list(array, del);
	if (!list)
		while (*array)
			del(*(array++));
	free(array);
	return (list);
}
