#include "libft.h"

void	iterator_reset(t_iterator *iterator)
{
	if (iterator->list)
		iterator->current = iterator->list->first;
}

void	citerator_reset(t_citerator *iterator)
{
	if (iterator->list)
		iterator->current = iterator->list->first;
}
