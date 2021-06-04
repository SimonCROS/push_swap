#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef enum e_action		t_action;
typedef enum e_stack		t_stack;

enum e_action
{
	SWAP,
	PUSH,
	ROTATE,
	REVERSE_ROTATE
};

enum e_stack
{
	A,
	B,
	BOTH
};

void	arr_shift_left(int *array, int *size);
void	arr_shift_right(int *array, int *size);

#endif
