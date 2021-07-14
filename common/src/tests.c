#include "push_swap/ps_common.h"

int	is_valid(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size - 1)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->array[i] == a->array[j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	array_len(char **array)
{
	int	i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	array_is_sorted(int *array, int length)
{
	int	i;

	if (!array)
		return (FALSE);
	i = 0;
	while (i < length - 1)
	{
		if (array[i] > array[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
