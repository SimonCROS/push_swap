#include "libft.h"

void	*iterator_next(t_iterator *iterator)
{
	void	*tmp;

	if (!iterator->current)
		return (NULL);
	tmp = iterator->current->value;
	iterator->current = iterator->current->next;
	return (tmp);
}

void	*citerator_next(t_citerator *iterator)
{
	void	*tmp;

	if (!iterator->current)
		return (NULL);
	tmp = iterator->current;
	iterator->current = iterator->current->next;
	return (tmp);
}
