#ifndef STACK_H
# define STACK_H

typedef struct s_stack	t_stack;

struct s_stack
{
	int	*array;
	int	size;
};

void	stack_insert(t_stack *stack, int item, int index);
void	stack_unshift(t_stack *stack, int item);
void	stack_push(t_stack *stack, int item);
void	stack_shift_left(t_stack *stack);
void	stack_shift_right(t_stack *stack);
void	stack_shift_right_at(t_stack *stack, int index);
int		stack_shift(t_stack *stack);
int		stack_pop(t_stack *stack);

#endif
