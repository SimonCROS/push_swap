#include "libft.h"

int	iterator_has_next(const t_iterator *iterator)
{
	return (!!iterator->current);
}

int	citerator_has_next(const t_citerator *iterator)
{
	return (!!iterator->current);
}
