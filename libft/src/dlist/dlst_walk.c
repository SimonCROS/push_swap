#include "libft.h"

t_dentry	*dlst_walk_right(t_dentry *walk)
{
	if (!walk)
		return (NULL);
	if (walk->next)
		walk = walk->next;
	return (walk);
}

t_dentry	*dlst_walk_left(t_dentry *walk)
{
	if (!walk)
		return (NULL);
	if (!walk->previous)
		return (NULL);
	walk = walk->previous;
	return (walk);
}
