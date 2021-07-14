#include "libft.h"

void	dlst_destroy(t_dlist *list)
{
	dlst_clear(list);
	free(list);
}
