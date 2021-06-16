#include "push_swap/common.h"

static void	action_on(t_stack *stack, t_stack *other, t_action action)
{
	if (action == PUSH)
		stack_unshift(stack, stack_shift(other));
	if (action == SWAP)
		stack_insert(stack, stack_shift(stack), 1);
	if (action == ROTATE)
		stack_push(stack, stack_shift(stack));
	if (action == REVERSE_ROTATE)
		stack_unshift(stack, stack_pop(stack));
}

void	action(t_stack *a, t_stack *b, t_action action, t_stack_name stack)
{
	char	*operation;

	if (stack == A || stack == BOTH)
		action_on(a, b, action);
	if (stack == B || stack == BOTH)
		action_on(b, a, action);
	if (action == PUSH)
		operation = "p";
	else if (action == SWAP)
		operation = "s";
	else if (action == ROTATE)
		operation = "r";
	else
		operation = "rr";
	ft_putstr(operation);
	if (stack == A)
		ft_putchar('a');
	else if (stack == B)
		ft_putchar('b');
	else if (stack == BOTH)
		ft_putchar(operation[0]);
	ft_putchar('\n');
}
