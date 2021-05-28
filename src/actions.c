#include "push_swap.h"

int	action_on(t_list *stack, t_list *other, t_action action)
{
	if (action == PUSH)
		return (!!lst_unshift(stack, lst_shift(other)));
	if (action == SWAP)
		return (!!lst_insert(stack, 1, lst_shift(stack)));
	if (action == ROTATE)
		return (!!lst_push(stack, lst_shift(stack)));
	if (action == REVERSE_ROTATE)
		return (!!lst_unshift(stack, lst_pop(stack)));
	return (FALSE);
}

int	action(t_list *a, t_list *b, t_action action, t_stack stack)
{
	int	ret;

	ret = 1;
	if (stack == BOTH && action == PUSH)
		return (FALSE);
	if (stack == A || stack == BOTH)
		ret *= action_on(a, b, action);
	if (stack == B || stack == BOTH)
		ret *= action_on(b, a, action);
	return (ret);
}
