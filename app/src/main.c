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
	int	half;

	while (b->size)
	{
		half = b->size / 2;
		move_biggest_to_top(a, b, b->size, -1);
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

void	start_sort(t_stack *a, t_stack *b)
{
	int	chunk_step;
	int	chunk_max;
	int	chunk_min;
	int	size;
	int	i;

	size = a->size;
	rank_array(&a->array, &b->array, a->size);
	chunk_max = 0;
	if (size >= 500)
	{
		i = 0;
		chunk_step = size / 2;
		while (i++ < 5)
		{
			chunk_min = chunk_max;
			chunk_max += chunk_step;
			make_chunk(a, b, chunk_min, chunk_max, FALSE);
			chunk_step /= 2;
		}
		i = 0;
		chunk_step = size / 32;
		while (i++ < 3)
		{
			chunk_min = chunk_max;
			chunk_max -= chunk_step;
			make_chunk(a, b, chunk_max, chunk_max + chunk_step, TRUE);
		}
		i = 0;
		chunk_step = size / 16;
		while (i++ < 4)
		{
			chunk_min = chunk_max;
			chunk_max -= chunk_step;
			make_chunk(a, b, chunk_max, chunk_max + chunk_step, TRUE);
		}
		i = 0;
		chunk_step = size / 8;
		while (i++ < 4)
		{
			chunk_min = chunk_max;
			chunk_max -= chunk_step;
			make_chunk(a, b, chunk_max, chunk_max + chunk_step, TRUE);
		}
		i = 0;
		chunk_step = size / 6;
		while (i++ < 2)
		{
			chunk_min = chunk_max;
			chunk_max -= chunk_step;
			make_chunk(a, b, chunk_max, chunk_max + chunk_step, TRUE);
		}
		chunk_step = size / 32;
		chunk_max = 0;
		chunk_min = 0;
		while (a->size > 0)
		{
			chunk_min = chunk_max;
			chunk_max += chunk_step;
			make_chunk(a, b, chunk_min, chunk_max, FALSE);
		}
	}
	else if (size >= 10)
	{
		chunk_step = size / 5;
		while (a->size > 0)
		{
			chunk_min = chunk_max;
			chunk_max += chunk_step;
			make_chunk(a, b, chunk_min, chunk_max, FALSE);
		}
	}
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
