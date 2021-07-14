#include "libft.h"

int	dlst_is_empty(t_dlist *list)
{
	if (!list)
		return (1);
	return (!(list->first));
}

int	dlst_not_empty(t_dlist *list)
{
	if (!list)
		return (1);
	return (!!(list->first));
}
