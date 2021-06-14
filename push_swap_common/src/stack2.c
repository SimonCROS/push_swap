#include "stack.h"

void	stack_insert(t_stack *stack, int item, int index)
{
	stack_shift_right_at(stack, index);
	stack->array[index] = item;
}

void	stack_unshift(t_stack *stack, int item)
{
	stack_shift_right(stack);
	stack->array[0] = item;
}

void	stack_push(t_stack *stack, int item)
{
	stack->array[stack->size] = item;
	stack->size++;
}
