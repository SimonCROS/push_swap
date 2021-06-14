#ifndef PUSH_SWAP_COMMON_H
# define PUSH_SWAP_COMMON_H

# include "stack.h"

static void	action_on(int *stack, int *other, t_action action, int *size, int *size_other);
void		action(int *a, int *b, t_action action, t_stack stack, int *sizea, int *sizeb);

#endif
