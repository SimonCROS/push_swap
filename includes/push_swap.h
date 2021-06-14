#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

#include <stdio.h>//

int		arr_pop(int *array, int *size);
int		arr_shift(int *array, int *size);
void	arr_shift_left(int *array, int *size);
void	arr_shift_right(int *array, int *size);
void	arr_push(int *array, int item, int *size);
void	arr_unshift(int *array, int item, int *size);
void	arr_shift_right_at(int *array, int *size, int index);
void	arr_insert(int *array, int item, int *size, int index);

void	action(int *a, int *b, int *sizea, int *sizeb, t_action action, t_stack_name stack);

void	print_stacks(int *a, int *b, int size_a, int size_b);

#endif
