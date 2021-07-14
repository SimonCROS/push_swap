#include "libft.h"

t_list	*lst_copy(t_list *list)
{
	return (lst_map(list, ft_identity(), list->del));
}
