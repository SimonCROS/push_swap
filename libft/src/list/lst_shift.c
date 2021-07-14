#include "libft.h"

void	*clst_shift(t_clist *list)
{
	t_centry	*first;

	if (clst_is_empty(list))
		return (NULL);
	first = list->first;
	list->first = first->next;
	--(list->size);
	return (first);
}

void	*lst_shift(t_list *list)
{
	t_entry	*first;
	void	*value;

	if (lst_is_empty(list))
		return (NULL);
	first = lst_shift_entry(list);
	value = first->value;
	free(first);
	return (value);
}
