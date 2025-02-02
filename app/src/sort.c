#include "push_swap/ps_common.h"
#include "push_swap/ps_app.h"

void	named_stack_action(t_named_stack *stack, t_named_stack *other,
	t_action a, t_stack_name stack_name)
{
	if (stack->name == A)
		action((t_stack *)stack, (t_stack *)other, a, stack_name);
	else
		action((t_stack *)other, (t_stack *)stack, a, stack_name);
}

static void	move_biggest_to_top(t_stack *a, t_stack *b, int biggest, int biggest_i)
{
	int		half;
	int		i;

	i = 0;
	half = b->size / 2;
	while (i < b->size)
	{
		if (stack_get(b, i) > biggest)
		{
			biggest = stack_get(b, i);
			biggest_i = i;
			if (i > half * 1.5)
				biggest_i = -(b->size - i);
		}
		i++;
	}
	i = 0;
	if (biggest_i > 0)
		while (i++ < biggest_i)
			action(a, b, ROTATE, B);
	else
		while (i-- > biggest_i)
			action(a, b, REVERSE_ROTATE, B);
}

static void	finish(t_stack *a, t_stack *b)
{
	while (b->size)
	{
		move_biggest_to_top(a, b, -1, b->size);
		action(a, b, PUSH, A);
	}
}

static void	make_under_10(t_named_stack *a, t_named_stack *b)
{
	int	chunk_max;

	chunk_max = 0;
	while (a->super.size > 3)
	{
		chunk_max += 3;
		make_chunk(a, b, 0, chunk_max);
	}
	if (a->super.size == 3)
	{
		if (stack_get((t_stack *)a, 0) > stack_get((t_stack *)a, 1)
			&& stack_get((t_stack *)a, 0) > stack_get((t_stack *)a, 2))
			named_stack_action(a, b, ROTATE, A);
		else if (stack_get((t_stack *)a, 1) > stack_get((t_stack *)a, 2))
			named_stack_action(a, b, SWAP, A);
		if (stack_get((t_stack *)a, 0) > stack_get((t_stack *)a, 2))
			named_stack_action(a, b, ROTATE, A);
	}
	if (a->super.size >= 2)
		if (stack_get((t_stack *)a, 0) > stack_get((t_stack *)a, 1))
			named_stack_action(a, b, SWAP, A);
}

void	start_sort(t_named_stack *a, t_named_stack *b)
{
	int	size;

	size = a->super.size;
	rank_array(&a->super.array, &b->super.array, a->super.size);
	if (size >= 500)
		iter_chunk(a, b, (int [5]){size, -1, 32, FALSE, FALSE},
			iter_chunk(a, b, (int [5]){size, 2, 6, FALSE, TRUE},
				iter_chunk(a, b, (int [5]){size, 4, 8, FALSE, TRUE},
					iter_chunk(a, b, (int [5]){size, 4, 16, FALSE, TRUE},
						iter_chunk(a, b, (int [5]){size, 3, 32, FALSE, TRUE},
							iter_chunk(a, b, (int [5]){size, 5, 2, TRUE, FALSE},
								0))))));
	else if (size >= 10)
		iter_chunk(a, b, (int [5]){size, -1, 5, FALSE, FALSE}, 0);
	else
		make_under_10(a, b);
	finish((t_stack *)a, (t_stack *)b);
}
