#ifndef STACK_H
# define STACK_H

# include <stddef.h>

typedef struct s_looping_stack	t_stack;

struct s_looping_stack
{
	int		*array;
	int		size;
	size_t	start;
	size_t	capacity;
};

int		stack_get(const t_stack *stack, size_t index);
int		stack_shift(t_stack *stack);
int		stack_pop(t_stack *stack);
void	stack_unshift(t_stack *stack, int item);
void	stack_push(t_stack *stack, int item);

#endif
