#include "libft.h"

t_clist	*clst_new(t_consumer del)
{
	t_clist	*list;

	list = malloc(sizeof(t_clist));
	if (!list)
		return (NULL);
	list->del = del;
	list->size = 0;
	list->first = NULL;
	return (list);
}

t_list	*lst_new(t_consumer del)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->del = del;
	list->size = 0;
	list->first = NULL;
	return (list);
}
