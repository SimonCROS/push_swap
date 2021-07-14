#include "libft.h"

int	lst_insert(t_list *list, int index, void *value)
{
	t_list	*new_empty;

	new_empty = lst_splice(list, index, 0, value);
	if (!new_empty)
		return (list->size);
	free(new_empty);
	return (list->size);
}
