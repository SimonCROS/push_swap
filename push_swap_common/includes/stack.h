#ifndef STACK_H
# define STACK_H

void	stack_insert(int *array, int item, int *size, int index);
void	stack_unshift(int *array, int item, int *size);
void	stack_push(int *array, int item, int *size);
void	stack_shift_left(int *array, int *size);
void	stack_shift_right(int *array, int *size);
void	stack_shift_right_at(int *array, int *size, int index);
int		stack_shift(int *stack, int *size);
int		stack_pop(int *array, int *size);

#endif
