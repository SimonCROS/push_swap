#include "push_swap/ps_common.h"

static void	swap(t_stack *stack) {
	int	first;
	int	second;

	first = stack_shift(stack);
	second = stack_shift(stack);
	stack_unshift(stack, first);
	stack_unshift(stack, second);
}

void	action_on(t_stack *stack, t_stack *other, t_action action)
{
	if (action == PUSH && other->size)
	{
		stack_unshift(stack, stack_shift(other));
	}
	else if (stack->size > 1)
	{
		if (action == SWAP)
			swap(stack);
		else if (action == ROTATE)
			stack_push(stack, stack_shift(stack));
		else if (action == REVERSE_ROTATE)
			stack_unshift(stack, stack_pop(stack));
	}
}

void	action(t_stack *a, t_stack *b, t_action action, t_stack_name name)
{
	char	*operations;

	if (name == A || name == BOTH)
		action_on(a, b, action);
	if (name == B || name == BOTH)
		action_on(b, a, action);
	// 42 norm does not allow inline array initialization, so I use this literal as an array
	operations = "sa\n\0 sb\n\0 ss\n\0 pa\n\0 pb\n\0 pp\n\0 ra\n\0 rb\n\0 rr\n\0 rra\n\0rrb\n\0rrr\n\0";
	// 3 variants for each operation, each in a string of length 5
	ft_putstr(operations + ((action * 3) + name) * 5);
}
