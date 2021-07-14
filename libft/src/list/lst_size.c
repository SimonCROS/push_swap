#include "libft.h"

int	lst_size(t_list *list)
{
	t_entry	*entry;
	int		i;

	if (lst_is_empty(list))
		return (0);
	entry = list->first;
	i = 1;
	while (entry->next)
	{
		entry = entry->next;
		++i;
	}
	return (i);
}
