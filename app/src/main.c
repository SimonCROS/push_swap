#include "push_swap/common.h"

int	find_nearest(const t_stack *stack, int chunk_min, int chunk_max)
{
	int				nearest;
	int				i;

	nearest = stack->size;
	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i] >= chunk_min && stack->array[i] < chunk_max)
		{
			nearest = i;
			break ;
		}
		i++;
	}
	i = stack->size;
	while (i-- > 0 && stack->size - i < nearest * 0.5)
	{
		if (stack->array[i] >= chunk_min && stack->array[i] < chunk_max)
		{
			nearest = -(stack->size - i);
			break ;
		}
	}
	return (nearest);
}

void	make_chunk(t_stack *a, t_stack *b, int chunk_min, int chunk_max,
	int reversed)
{
	int				nearest;
	int				i;
	int				middle;
	t_stack			*p;
	t_stack			*o;

	p = a;
	o = b;
	if (reversed)
	{
		p = b;
		o = a;
	}
	middle = chunk_min + (chunk_max - chunk_min) / 2;
	while (p->size)
	{
		nearest = find_nearest(p, chunk_min, chunk_max);
		if (nearest == p->size)
			break ;
		i = 0;
		if (nearest > 0)
		{
			while (i++ < nearest)
			{
				if (o->size && o->array[0] < middle)
					action(a, b, ROTATE, BOTH);
				else
					action(a, b, ROTATE, ft_ternary(!reversed, A, B));
			}
		}
		else
			while (i-- > nearest)
				action(a, b, REVERSE_ROTATE, ft_ternary(!reversed, A, B));
		action(a, b, PUSH, ft_ternary(!reversed, B, A));
	}
}

static void	move_biggest_to_top(t_stack *a, t_stack *b, int biggest,
		int biggest_i)
{
	int	half;
	int	i;

	i = 0;
	half = b->size / 2;
	while (i < b->size)
	{
		if (b->array[i] > biggest)
		{
			biggest = b->array[i];
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

void	finish(t_stack *a, t_stack *b)
{
	while (b->size)
	{
		move_biggest_to_top(a, b, -1, b->size);
		action(a, b, PUSH, A);
	}
}

static void	make_under_10(t_stack *a, t_stack *b)
{
	int	chunk_max;

	chunk_max = 0;
	while (a->size > 3)
	{
		chunk_max += 3;
		make_chunk(a, b, 0, chunk_max, FALSE);
	}
	if (a->size == 3)
	{
		if (a->array[0] > a->array[1] && a->array[0] > a->array[2])
			action(a, b, ROTATE, A);
		else if (a->array[1] > a->array[2])
			action(a, b, SWAP, A);
		if (a->array[0] > a->array[2])
			action(a, b, ROTATE, A);
	}
	if (a->size >= 2)
		if (a->array[0] > a->array[1])
			action(a, b, SWAP, A);
}

/**
 * @param options[0] iterations
 * @param options[1] steps
 * @param options[2] reduce on iterate
 * @param options[3] reverse
 */
static int	iter_chunk(t_stack *a, t_stack *b, int size, int options[4],
	int chunk_max)
{
	t_stack	*p;
	int		chunk_step;
	int		chunk_min;
	int		i;

	p = a;
	if (options[3])
		p = b;
	i = 0;
	chunk_step = size / options[1];
	while (i++ != options[0] && p->size)
	{
		chunk_min = chunk_max;
		if (!options[3])
		{
			chunk_max += chunk_step;
			make_chunk(a, b, chunk_min, chunk_max, FALSE);
		}
		else
		{
			chunk_max -= chunk_step;
			make_chunk(a, b, chunk_max, chunk_max + chunk_step, TRUE);
		}
		if (options[2])
			chunk_step /= 2;
	}
	return (chunk_max);
}

void	start_sort(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	rank_array(&a->array, &b->array, a->size);
	if (size >= 500)
		iter_chunk(a, b, size, (int [4]){-1, 32, FALSE, FALSE},
			iter_chunk(a, b, size, (int [4]){2, 6, FALSE, TRUE},
				iter_chunk(a, b, size, (int [4]){4, 8, FALSE, TRUE},
					iter_chunk(a, b, size, (int [4]){4, 16, FALSE, TRUE},
						iter_chunk(a, b, size, (int [4]){3, 32, FALSE, TRUE},
							iter_chunk(a, b, size, (int [4]){5, 2, TRUE, FALSE},
								0))))));
	else if (size >= 10)
		iter_chunk(a, b, size, (int [4]){-1, 5, FALSE, FALSE}, 0);
	else
		make_under_10(a, b);
	finish(a, b);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		ret;

	if (argc == 1)
		return (EXIT_SUCCESS);
	a = init_numbers(argv + 1, argc - 1, &b);
	ret = EXIT_SUCCESS;
	if (!a.array || !b.array || !is_valid(&a))
		ret = EXIT_FAILURE;
	else if (!array_is_sorted(a.array, a.size))
		start_sort(&a, &b);
	free(a.array);
	free(b.array);
	if (ret == EXIT_FAILURE)
		ft_putendl_fd("Error", 2);
	return (ret);
}
