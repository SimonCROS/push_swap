#ifndef PS_APP_H
# define PS_APP_H

# include "stack.h"

typedef struct s_named_stack	t_named_stack;

struct s_named_stack
{
	t_stack			super;
	t_stack_name	name;
};

int		iter_chunk(t_named_stack *a, t_named_stack *b, int options[5],
			int chunk_max);
void	make_chunk(t_named_stack *a, t_named_stack *b, int chunk_min,
			int chunk_max);
void	named_stack_action(t_named_stack *stack, t_named_stack *other,
			t_action a, t_stack_name stack_name);

#endif
