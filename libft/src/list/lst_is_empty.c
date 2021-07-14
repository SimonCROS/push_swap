#include "libft.h"

int	clst_is_empty(t_clist *list)
{
	if (!list)
		return (1);
	return (!(list->first));
}

int	clst_not_empty(t_clist *list)
{
	if (!list)
		return (1);
	return (!!(list->first));
}

int	lst_is_empty(t_list *list)
{
	if (!list)
		return (1);
	return (!(list->first));
}

int	lst_not_empty(t_list *list)
{
	if (!list)
		return (1);
	return (!!(list->first));
}
