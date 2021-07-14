#include "libft.h"

t_entry	*lst_new_entry(void *value)
{
	t_entry	*entry;

	entry = malloc(sizeof(t_entry));
	if (!entry)
		return (NULL);
	entry->value = value;
	entry->next = NULL;
	return (entry);
}
