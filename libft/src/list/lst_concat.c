#include "libft.h"

t_list	*lst_concat(t_list *t1, t_list *t2)
{
	t_list	*copy;

	if (t1->del != t2->del)
		return (NULL);
	copy = lst_new(t1->del);
	if (!copy)
		return (NULL);
	lst_add_all(copy, t1);
	lst_add_all(copy, t2);
	return (copy);
}
