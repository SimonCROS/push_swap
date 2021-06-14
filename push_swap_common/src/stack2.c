#include "push_swap.h"

void	stack_insert(int *array, int item, int *size, int index)
{
	stack_shift_right_at(array, size, index);
	array[index] = item;
}

void	stack_unshift(int *array, int item, int *size)
{
	stack_shift_right(array, size);
	array[0] = item;
}

void	stack_push(int *array, int item, int *size)
{
	array[*size] = item;
	(*size)++;
}
