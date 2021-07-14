#ifndef PS_COMMON_H
# define PS_COMMON_H

# include "libft.h"
# include "stack.h"

typedef enum e_action			t_action;
typedef enum e_stack_name		t_stack_name;

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

void	action_on(t_stack *stack, t_stack *other, t_action action);
void	action(t_stack *a, t_stack *b, t_action action, t_stack_name name);

t_stack	init_numbers(char **argv, int size, t_stack *stack2);
void	rank_array(int **arr, int **rank, int size);

int		is_valid(t_stack *a);
int		array_len(char **array);
int		array_is_sorted(int *array, int length);

#endif
