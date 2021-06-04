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
	int	i;

	i = *size - 1;
	while (i > 0)
	{
		array[i] = array[i - 1];
		i--;
	}
	array[i] = 0;
	(*size)++;
}

// void	arr_unshift(int *stack, int item, int *size)
// {
// 	arr_shift_right(stack, size);
// 	stack[0] = item;
// }

// void	arr_push(int *stack, int item, int *size)
// {
// 	stack[*size] = item;
// 	(*size)++;
// }

// void	action_on(int *stack, int *other, t_action action)
// {
// 	// if (action == PUSH)
// 	// 	lst_unshift(stack, lst_shift(other));
// 	// if (action == SWAP)
// 	// 	lst_insert(stack, 1, lst_shift(stack));
// 	// if (action == ROTATE)
// 	// 	lst_push(stack, lst_shift(stack));
// 	// if (action == REVERSE_ROTATE)
// 	// 	lst_unshift(stack, lst_pop(stack));
// }

// void	action(int *a, int *b, t_action action, t_stack stack)
// {
// 	// if (stack == A || stack == BOTH)
// 	// 	action_on(a, b, action);
// 	// if (stack == B || stack == BOTH)
// 	// 	action_on(b, a, action);
// }
