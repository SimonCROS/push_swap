#include "libft.h"

t_dentry	*dlst_shift_entry(t_dlist *list)
{
	t_dentry	*first;

	if (dlst_is_empty(list))
		return (NULL);
	first = list->first;
	list->first = first->next;
	list->first->previous = NULL;
	--(list->size);
	return (first);
}

void	*dlst_shift(t_dlist *list)
{
	t_dentry	*first;
	void		*value;

	if (dlst_is_empty(list))
		return (NULL);
	first = dlst_shift_entry(list);
	value = first->value;
	free(first);
	return (value);
}

void	*dlst_unshift(t_dlist *list, void *element)
{
	t_dentry	*entry;

	entry = dlst_new_entry(element);
	if (!entry)
		return (NULL);
	entry->next = list->first;
	if (list->first)
		list->first->previous = entry;
	list->first = entry;
	++(list->size);
	return (element);
}
