#include "push_swap/ps_common.h"

t_stack	init_numbers(char **argv, int size, t_stack *stack2)
{
	int	*array;
	int	i;

	stack2->array = ft_calloc(size, sizeof(int));
	stack2->size = 0;
	stack2->start = 0;
	stack2->capacity = size;
	array = ft_calloc(size, sizeof(int));
	i = 0;
	while (i < size)
	{
		if (array && !ft_atoi_full(argv[i], &array[i]))
		{
			free(array);
			array = NULL;
		}
		i++;
	}
	return ((t_stack){array, size, 0, size});
}

void	rank_array(int **arr, int **rank, int size)
{
	int	*tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if ((*arr)[i] > (*arr)[j])
				(*rank)[i]++;
			j++;
		}
		i++;
	}
	tmp = *rank;
	*rank = *arr;
	*arr = tmp;
}
