#include "push_swap/common.h"

void	make_chunk(t_stack *a, t_stack *b, int chunk_min, int chunk_max, int reversed)
{
	int				j;
	int				middle;
	t_stack			*p;
	t_stack			*o;
	int				nearest;

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
		nearest = p->size;
		j = 0;
		while (j < p->size)
		{
			if (p->array[j] >= chunk_min && p->array[j] < chunk_max)
			{
				nearest = j;
				break ;
			}
			j++;
		}
		j = p->size;
		while (j-- > 0)
		{
			if (p->size - j >= nearest * 0.5)
				break ;
			if (p->array[j] >= chunk_min && p->array[j] < chunk_max)
			{
				nearest = -(p->size - j);
				break ;
			}
		}
		if (nearest == p->size)
			break ;
		j = 0;
		if (nearest > 0)
		{
			while (j++ < nearest)
			{
				if (o->size && o->array[0] < middle)
					action(a, b, ROTATE, BOTH);
				else
					action(a, b, ROTATE, ft_ternary(!reversed, A, B));
			}
		}
		else
			while (j-- > nearest)
				action(a, b, REVERSE_ROTATE, ft_ternary(!reversed, A, B));
		action(a, b, PUSH, ft_ternary(!reversed, B, A));
	}
}

void	finish(t_stack *a, t_stack *b)
{
	int	biggest_i;
	int	biggest;
	int	half;
	int	i;

	while (b->size)
	{
		i = 0;
		half = b->size / 2;
		biggest_i = b->size;
		biggest = -1;
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
		action(a, b, PUSH, A);
		i++;
	}
}

void	start_sort(t_stack *a, t_stack *b)
{
	int	chunk_step;
	int	chunk_min;
	int	chunk_max;
	int	size;

	size = a->size;
	rank_array(&a->array, &b->array, a->size);
	chunk_max = 0;
	if (size >= 500)
	{
		chunk_step = size / 2;
		chunk_min = chunk_max;
		chunk_max += chunk_step;
		make_chunk(a, b, chunk_min, chunk_max, FALSE);
		chunk_step = size / 4;
		chunk_min = chunk_max;
		chunk_max += chunk_step;
		make_chunk(a, b, chunk_min, chunk_max, FALSE);
		chunk_step = size / 8;
		chunk_min = chunk_max;
		chunk_max += chunk_step;
		make_chunk(a, b, chunk_min, chunk_max, FALSE);
		chunk_step = size / 16;
		chunk_min = chunk_max;
		chunk_max += chunk_step;
		make_chunk(a, b, chunk_min, chunk_max, FALSE);
		chunk_step = size / 32;
		chunk_min = chunk_max;
		chunk_max += chunk_step;
		make_chunk(a, b, chunk_min, chunk_max, FALSE);

		chunk_step = size / 32;
		chunk_max -= chunk_step;
		make_chunk(a, b, chunk_max, chunk_max + chunk_step, TRUE);
		chunk_max -= chunk_step;
		make_chunk(a, b, chunk_max, chunk_max + chunk_step, TRUE);
		chunk_max -= chunk_step;
		make_chunk(a, b, chunk_max, chunk_max + chunk_step, TRUE);
		chunk_step = size / 16;
		chunk_max -= chunk_step;
		make_chunk(a, b, chunk_max, chunk_max + chunk_step, TRUE);
		chunk_max -= chunk_step;
		make_chunk(a, b, chunk_max, chunk_max + chunk_step, TRUE);
		chunk_max -= chunk_step;
		make_chunk(a, b, chunk_max, chunk_max + chunk_step, TRUE);
		chunk_max -= chunk_step;
		make_chunk(a, b, chunk_max, chunk_max + chunk_step, TRUE);
		chunk_step = size / 8;
		chunk_max -= chunk_step;
		make_chunk(a, b, chunk_max, chunk_max + chunk_step, TRUE);
		chunk_max -= chunk_step;
		make_chunk(a, b, chunk_max, chunk_max + chunk_step, TRUE);
		chunk_max -= chunk_step;
		make_chunk(a, b, chunk_max, chunk_max + chunk_step, TRUE);
		chunk_max -= chunk_step;
		make_chunk(a, b, chunk_max, chunk_max + chunk_step, TRUE);
		chunk_step = size / 6;
		chunk_max -= chunk_step;
		make_chunk(a, b, chunk_max, chunk_max + chunk_step, TRUE);
		chunk_max -= chunk_step;
		make_chunk(a, b, chunk_max, chunk_max + chunk_step, TRUE);
		chunk_step = size / 32;
		chunk_max = 0;
		chunk_min = 0;
		while (a->size > 0)
		{
			chunk_max += chunk_step;
			make_chunk(a, b, chunk_min, chunk_max, FALSE);
			chunk_min = chunk_max;
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
	{
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
