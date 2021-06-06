#include "push_swap.h"

void	arr_shift_left(int *array, int *size)
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

void	arr_shift_right(int *array, int *size)
{
	arr_shift_right_at(array, size, 0);
}

void	arr_shift_right_at(int *array, int *size, int index)
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

int	arr_shift(int *stack, int *size)
{
	int	tmp;

	tmp = stack[0];
	arr_shift_left(stack, size);
	return (tmp);
}

int	arr_pop(int *array, int *size)
{
	int	tmp;

	tmp = array[*size - 1];
	(*size)--;
	return (tmp);
}

void	arr_insert(int *array, int item, int *size, int index)
{
	arr_shift_right_at(array, size, index);
	array[index] = item;
}

void	arr_unshift(int *array, int item, int *size)
{
	arr_shift_right(array, size);
	array[0] = item;
}

void	arr_push(int *array, int item, int *size)
{
	array[*size] = item;
	(*size)++;
}

static void	action_on(int *stack, int *other, t_action action, int *size, int *size_other)
{
	if (action == PUSH)
		arr_unshift(stack, arr_shift(other, size_other), size);
	if (action == SWAP)
		arr_insert(stack, arr_shift(stack, size), size, 1);
	if (action == ROTATE)
		arr_push(stack, arr_shift(stack, size), size);
	if (action == REVERSE_ROTATE)
		arr_unshift(stack, arr_pop(stack, size), size);
}

void	action(int *a, int *b, t_action action, t_stack stack, int *sizea, int *sizeb)
{
	if (stack == A || stack == BOTH)
		action_on(a, b, action, sizea, sizeb);
	if (stack == B || stack == BOTH)
		action_on(b, a, action, sizeb, sizea);
	print_stacks(a, b, *sizea, *sizeb);
}
