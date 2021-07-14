#include "libft.h"

void	dlst_free(t_dlist *list)
{
	t_dentry	*entry;

	if (dlst_is_empty(list))
		return ;
	entry = dlst_shift_entry(list);
	while (entry)
	{
		free(entry);
		entry = dlst_shift_entry(list);
	}
	free(list);
}

void	dlst_clear(t_dlist *list)
{
	t_dentry	*entry;

	if (dlst_is_empty(list))
		return ;
	entry = dlst_shift_entry(list);
	while (entry)
	{
		if (list->del && entry->value)
			list->del(entry->value);
		free(entry);
		entry = dlst_shift_entry(list);
	}
}
