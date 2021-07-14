#include "libft.h"

t_dentry	*dlst_new_entry(void *value)
{
	t_dentry	*entry;

	entry = malloc(sizeof(t_dentry));
	if (!entry)
		return (NULL);
	entry->value = value;
	entry->next = NULL;
	entry->previous = NULL;
	return (entry);
}

t_dlist	*dlst_new(t_consumer del)
{
	t_dlist	*list;

	list = malloc(sizeof(t_dlist));
	if (!list)
		return (NULL);
	list->del = del;
	list->size = 0;
	list->first = NULL;
	return (list);
}
