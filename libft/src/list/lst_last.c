#include "libft.h"

void	*lst_last(t_list *list)
{
	if (lst_is_empty(list))
		return (NULL);
	return (lst_last_entry(list)->value);
}
