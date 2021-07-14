#include "libft.h"

t_entry	*lst_shift_entry(t_list *list)
{
	t_entry	*first;

	if (lst_is_empty(list))
		return (NULL);
	first = list->first;
	list->first = first->next;
	--(list->size);
	return (first);
}
