#include "looping_stack.h"

int	stack_get(const t_stack *stack, size_t index)
{
	return (stack->array[(stack->start + index) % stack->capacity]);
}

int	stack_shift(t_stack *stack)
{
	int	tmp;

	tmp = stack->array[stack->start];
	stack->start = (stack->start + 1) % stack->capacity;
	--stack->size;
	return (tmp);
}

int	stack_pop(t_stack *stack)
{
	int		tmp;
	size_t	last_index;

	last_index = (stack->start + stack->size - 1) % stack->capacity;
	tmp = stack->array[last_index];
	--stack->size;
	return (tmp);
}

void	stack_unshift(t_stack *stack, int item)
{
	size_t	rend_index;

	if (stack->start > 0)
		rend_index = stack->start - 1;
	else
		rend_index = stack->capacity - 1;
	stack->array[rend_index] = item;
	stack->start = rend_index;
	++stack->size;
}

void	stack_push(t_stack *stack, int item)
{
	size_t	end_index;

	end_index = (stack->start + stack->size) % stack->capacity;
	stack->array[end_index] = item;
	++stack->size;
}
