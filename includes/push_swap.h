#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

#include <stdio.h>//

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

int		arr_pop(int *array, int *size);
int		arr_shift(int *array, int *size);
void	arr_shift_left(int *array, int *size);
void	arr_shift_right(int *array, int *size);
void	arr_push(int *array, int item, int *size);
void	arr_unshift(int *array, int item, int *size);
void	arr_shift_right_at(int *array, int *size, int index);
void	arr_insert(int *array, int item, int *size, int index);

void	action(int *a, int *b, t_action action, t_stack stack, int *sizea, int *sizeb);

void	print_stacks(int *a, int *b, int size_a, int size_b);

#endif
