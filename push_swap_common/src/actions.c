#include "push_swap.h"

static void	action_on(int *stack, int *other, t_action action, int *size, int *size_other)
{
	if (action == PUSH)
		stack_unshift(stack, stack_shift(other, size_other), size);
	if (action == SWAP)
		stack_insert(stack, stack_shift(stack, size), size, 1);
	if (action == ROTATE)
		stack_push(stack, stack_shift(stack, size), size);
	if (action == REVERSE_ROTATE)
		stack_unshift(stack, stack_pop(stack, size), size);
}

void	action(int *a, int *b, t_action action, t_stack stack, int *sizea, int *sizeb)
{
	char	*operation;

	if (stack == A || stack == BOTH)
		action_on(a, b, action, sizea, sizeb);
	if (stack == B || stack == BOTH)
		action_on(b, a, action, sizeb, sizea);
	if (action == PUSH)
		operation = "p";
	else if (action == SWAP)
		operation = "s";
	else if (action == ROTATE)
		operation = "r";
	else
		operation = "rr";
	if (stack == A)
		printf("%sa", operation);
	else if (stack == B)
		printf("%sb", operation);
	else if (stack == BOTH)
		printf("%s%c", operation, operation[0]);
	printf("\n");
}
