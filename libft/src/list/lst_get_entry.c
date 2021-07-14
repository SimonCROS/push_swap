#include "libft.h"

t_entry	*lst_get_entry(t_list *list, int index)
{
	t_entry	*entry;
	int		i;

	if (lst_is_empty(list))
		return (NULL);
	entry = list->first;
	i = 0;
	while (entry)
	{
		if (i == index)
			return (entry);
		entry = entry->next;
		++i;
	}
	return (NULL);
}
