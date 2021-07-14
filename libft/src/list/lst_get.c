#include "libft.h"

void	*lst_get(t_list *list, int index)
{
	t_entry	*entry;

	entry = lst_get_entry(list, index);
	if (!entry)
		return (NULL);
	return (entry->value);
}
