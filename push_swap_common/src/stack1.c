#include "push_swap.h"

void	stack_shift_left(int *array, int *size)
{
	int	i;

	i = 0;
	while (i < *size - 1)
	{
		array[i] = array[i + 1];
		i++;
	}
	array[i] = 0;
	(*size)--;
}

void	stack_shift_right(int *array, int *size)
{
	stack_shift_right_at(array, size, 0);
}

void	stack_shift_right_at(int *array, int *size, int index)
{
	int	i;

	i = *size;
	while (i > index)
	{
		array[i] = array[i - 1];
		i--;
	}
	array[i] = 0;
	(*size)++;
}

int	stack_shift(int *stack, int *size)
{
	int	tmp;

	tmp = stack[0];
	stack_shift_left(stack, size);
	return (tmp);
}

int	stack_pop(int *array, int *size)
{
	int	tmp;

	tmp = array[*size - 1];
	(*size)--;
	return (tmp);
}
