#include "libft.h"

void	clst_destroy(t_clist *list)
{
	clst_clear(list);
	free(list);
}

void	lst_destroy(t_list *list)
{
	lst_clear(list);
	free(list);
}
