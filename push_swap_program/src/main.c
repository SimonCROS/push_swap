#include "push_swap/common.h"

int	array_len(char **array)
{
	int	i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
		i++;
	return (i);
}

t_stack	init_numbers(char **str, int size, int destroy, t_stack *stack2)
{
	int	*array;
	int	i;

	if (!str)
		return ((t_stack){NULL, size});
	stack2->array = calloc(size, sizeof(int));
	array = calloc(size, sizeof(int));
	i = 0;
	while (i < size)
	{
		if (array && !ft_atoi_full(str[i], &array[i]))
		{
			free(array);
			array = NULL;
		}
		if (destroy)
			free(str[i]);
		i++;
	}
	if (destroy)
		free(str);
	return ((t_stack){array, size});
}

void	rank_array(int **arr, int **rank, int size)
{
	int	*tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if ((*arr)[i] > (*arr)[j])
				(*rank)[i]++;
			j++;
		}
		i++;
	}
	tmp = *rank;
	*rank = *arr;
	*arr = tmp;
}

void	make_chunk(t_stack *a, t_stack *b, int chunk_max)
{
	int	nearest;
	int	half;
	int	j;

	while (a->size)
	{
		half = a->size / 2;
		nearest = a->size;
		j = 0;
		while (j < half + 1)
		{
			if (a->array[j] < chunk_max)
			{
				nearest = j;
				break ;
			}
			j++;
		}
		j = a->size;
		while (j-- > half)
		{
			if (a->size - j >= nearest)
				break ;
			if (a->array[j] < chunk_max)
			{
				nearest = -(a->size - j);
				break ;
			}
		}
		if (nearest == a->size)
			return ;
		j = 0;
		if (nearest > 0)
			while (j++ < nearest)
				action(a, b, ROTATE, A);
		else
			while (j-- > nearest)
				action(a, b, REVERSE_ROTATE, A);
		action(a, b, PUSH, B);
	}
}

void	make_chunki(t_stack *a, t_stack *b, int chunk_min)
{
	int	nearest;
	int	half;
	int	j;

	while (b->size)
	{
		half = b->size / 2;
		nearest = b->size;
		j = 0;
		while (j < half + 1)
		{
			if (b->array[j] > chunk_min)
			{
				nearest = j;
				break ;
			}
			j++;
		}
		j = b->size;
		while (j-- > half)
		{
			if (b->size - j >= nearest)
				break ;
			if (b->array[j] > chunk_min)
			{
				nearest = -(b->size - j);
				break ;
			}
		}
		if (nearest == b->size)
			return ;
		j = 0;
		if (nearest > 0)
			while (j++ < nearest)
				action(a, b, ROTATE, B);
		else
			while (j-- > nearest)
				action(a, b, REVERSE_ROTATE, B);
		action(a, b, PUSH, A);
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
				if (i > half)
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
	int	chunk_max;
	int	chunk_min;
	int	size;

	size = a->size;
	rank_array(&a, &b, a->size);
	if (size >= 500)
	{
		chunk_step = size / 4;
		chunk_max = chunk_step;
		while (a->size)
		{
			make_chunk(a, b, chunk_max);
			chunk_max += chunk_step;
		}
		chunk_step = size / 8;
		chunk_min = size;
		while (b->size)
		{
			chunk_min -= chunk_step;
			make_chunki(a, b, chunk_min);
		}
		chunk_step = size / 16;
		chunk_max = chunk_step;
		while (a->size)
		{
			make_chunk(a, b, chunk_max);
			chunk_max += chunk_step;
		}
	}
	else if (size >= 10)
	{
		chunk_step = size / 10;
		chunk_max = chunk_step;
		while (a->size)
		{
			make_chunk(a, b, chunk_max);
			chunk_max += chunk_step;
		}
	}
	else
	{
		chunk_max = 0;
		while (a->size > 3)
		{
			chunk_max += 3;
			make_chunk(a, b, chunk_max);
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

int main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		ret;
	int		size;
	void	*splitted;

	if (argc == 1)
		return (EXIT_SUCCESS);
	if (argc == 2)
	{
		splitted = ft_split(argv[1], ' ');
		size = array_len(splitted);
		a = init_numbers(splitted, size, 1, &b);
	}
	else
	{
		size = argc - 1;
		a = init_numbers(argv + 1, size, 0, &b);
	}
	ret = EXIT_SUCCESS;
	if (!a.array || !b.array)
		ret = EXIT_FAILURE;
	else
		start_sort(&a, &b);
	free(a.array);
	free(b.array);
	if (ret == EXIT_FAILURE)
		ft_putendl_fd("Error", 2);
	return (ret);
}
