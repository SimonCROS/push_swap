#include "push_swap/ps_common.h"
#include "push_swap/ps_app.h"

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

static void	finish(t_stack *a, t_stack *b)
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

static void	start_sort(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	rank_array(&a->array, &b->array, a->size);
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
