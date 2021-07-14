#include "libft.h"

void	*lst_set(t_list *list, int index, void *new_value)
{
	t_entry	*entry;
	void	*buf;

	entry = lst_get_entry(list, index);
	if (!entry)
		return (NULL);
	buf = entry->value;
	entry->value = new_value;
	return (buf);
}
