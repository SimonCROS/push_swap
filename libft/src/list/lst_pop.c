#include "libft.h"

void	*lst_pop(t_list *list)
{
	t_entry	**last_pointer;
	t_entry	*last;
	void	*value;

	if (lst_is_empty(list))
		return (NULL);
	last = list->first;
	last_pointer = &(list->first);
	while (last->next)
	{
		last_pointer = &(last->next);
		last = last->next;
	}
	value = last->value;
	free(last);
	*last_pointer = NULL;
	--(list->size);
	return (value);
}
