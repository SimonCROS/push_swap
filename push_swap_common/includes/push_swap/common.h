#ifndef COMMON_H
# define COMMON_H

# include "stack.h"

typedef enum e_action		t_action;
typedef enum e_stack_name	t_stack_name;

enum e_action
{
	SWAP,
	PUSH,
	ROTATE,
	REVERSE_ROTATE
};

enum e_stack_name
{
	A,
	B,
	BOTH
};

void	action(t_stack *a, t_stack *b, t_action action, t_stack_name stack);

#endif
