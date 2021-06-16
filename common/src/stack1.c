#include "stack.h"

void	stack_shift_left(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[i] = 0;
	stack->size--;
}

void	stack_shift_right(t_stack *stack)
{
	stack_shift_right_at(stack, 0);
}

void	stack_shift_right_at(t_stack *stack, int index)
{
	int	i;

	i = stack->size;
	while (i > index)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[i] = 0;
	stack->size++;
}

int	stack_shift(t_stack *stack)
{
	int	tmp;

	tmp = stack->array[0];
	stack_shift_left(stack);
	return (tmp);
}

int	stack_pop(t_stack *stack)
{
	int	tmp;

	tmp = stack->array[stack->size - 1];
	stack->size--;
	return (tmp);
}
