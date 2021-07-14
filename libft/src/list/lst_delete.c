#include "libft.h"

void	lst_delete(t_list *list, int index)
{
	void	*value;

	if (!list)
		return ;
	value = lst_remove(list, index);
	if (list->del && value)
		list->del(value);
}
