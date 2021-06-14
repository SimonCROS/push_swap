#include "push_swap.h"

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

int	*init_numbers(char **str, int size, int destroy, int **stack2)
{
	int	*result;
	int	i;

	if (!str)
		return (NULL);
	*stack2 = calloc(size, sizeof(int));
	result = calloc(size, sizeof(int));
	i = 0;
	while (i < size)
	{
		if (result && !ft_atoi_full(str[i], &result[i]))
		{
			free(result);
			result = NULL;
		}
		if (destroy)
			free(str[i]);
		i++;
	}
	if (destroy)
		free(str);
	return (result);
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

void	make_chunk(int *a, int *b, int *sizea, int *sizeb, int chunk_max)
{
	int	nearest;
	int	half;
	int	j;

	while (*sizea)
	{
		half = *sizea / 2;
		nearest = *sizea;
		j = 0;
		while (j < half + 1)
		{
			if (a[j] < chunk_max)
			{
				nearest = j;
				break ;
			}
			j++;
		}
		j = *sizea;
		while (j-- > half)
		{
			if (*sizea - j >= nearest)
				break ;
			if (a[j] < chunk_max)
			{
				nearest = -(*sizea - j);
				break ;
			}
		}
		if (nearest == *sizea)
			return ;
		j = 0;
		if (nearest > 0)
			while (j++ < nearest)
				action(a, b, ROTATE, A, sizea, sizeb);
		else
			while (j-- > nearest)
				action(a, b, REVERSE_ROTATE, A, sizea, sizeb);
		action(a, b, PUSH, B, sizea, sizeb);
	}
}

void	make_chunki(int *a, int *b, int *sizea, int *sizeb, int chunk_min)
{
	int	nearest;
	int	half;
	int	j;

	while (*sizeb)
	{
		half = *sizeb / 2;
		nearest = *sizeb;
		j = 0;
		while (j < half + 1)
		{
			if (b[j] > chunk_min)
			{
				nearest = j;
				break ;
			}
			j++;
		}
		j = *sizeb;
		while (j-- > half)
		{
			if (*sizeb - j >= nearest)
				break ;
			if (b[j] > chunk_min)
			{
				nearest = -(*sizeb - j);
				break ;
			}
		}
		if (nearest == *sizeb)
			return ;
		j = 0;
		if (nearest > 0)
			while (j++ < nearest)
				action(a, b, ROTATE, B, sizea, sizeb);
		else
			while (j-- > nearest)
				action(a, b, REVERSE_ROTATE, B, sizea, sizeb);
		action(a, b, PUSH, A, sizea, sizeb);
	}
}

void	finish(int *a, int *b, int *sizea, int *sizeb)
{
	int	biggest_i;
	int	biggest;
	int	half;
	int	i;

	while (*sizeb)
	{
		i = 0;
		half = *sizeb / 2;
		biggest_i = *sizeb;
		biggest = -1;
		while (i < *sizeb)
		{
			if (b[i] > biggest)
			{
				biggest = b[i];
				biggest_i = i;
				if (i > half)
					biggest_i = -(*sizeb - i);
			}
			i++;
		}
		i = 0;
		if (biggest_i > 0)
			while (i++ < biggest_i)
				action(a, b, ROTATE, B, sizea, sizeb);
		else
			while (i-- > biggest_i)
				action(a, b, REVERSE_ROTATE, B, sizea, sizeb);
		action(a, b, PUSH, A, sizea, sizeb);
		i++;
	}
}

void	start_sort(int *a, int *b, int size)
{
	int	chunk_step;
	int	chunk_max;
	int	chunk_min;
	int	sizea;
	int	sizeb;

	sizea = size;
	sizeb = 0;
	rank_array(&a, &b, size);
	if (size >= 500)
	{
		chunk_step = size / 4;
		chunk_max = chunk_step;
		while (sizea)
		{
			make_chunk(a, b, &sizea, &sizeb, chunk_max);
			chunk_max += chunk_step;
		}
		chunk_step = size / 8;
		chunk_min = size;
		while (sizeb)
		{
			chunk_min -= chunk_step;
			make_chunki(a, b, &sizea, &sizeb, chunk_min);
		}
		chunk_step = size / 16;
		chunk_max = chunk_step;
		while (sizea)
		{
			make_chunk(a, b, &sizea, &sizeb, chunk_max);
			chunk_max += chunk_step;
		}
	}
	else if (size >= 10)
	{
		chunk_step = size / 10;
		chunk_max = chunk_step;
		while (sizea)
		{
			make_chunk(a, b, &sizea, &sizeb, chunk_max);
			chunk_max += chunk_step;
		}
	}
	else
	{
		chunk_max = 0;
		while (sizea > 3)
		{
			chunk_max += 3;
			make_chunk(a, b, &sizea, &sizeb, chunk_max);
		}
		if (sizea == 3)
		{
			if (a[0] > a[1] && a[0] > a[2])
				action(a, b, ROTATE, A, &sizea, &sizeb);
			else if (a[1] > a[2])
				action(a, b, SWAP, A, &sizea, &sizeb);
			if (a[0] > a[2])
				action(a, b, ROTATE, A, &sizea, &sizeb);
		}
		if (sizea >= 2)
			if (a[0] > a[1])
				action(a, b, SWAP, A, &sizea, &sizeb);
	}
	finish(a, b, &sizea, &sizeb);
}

int main(int argc, char *argv[])
{
	int		ret;
	int		size;
	void	*splitted;
	int		*a;
	int		*b;

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
	if (!a || !b)
		ret = EXIT_FAILURE;
	else
		start_sort(a, b, size);
	free(a);
	free(b);
	if (ret == EXIT_FAILURE)
		ft_putendl_fd("Error", 2);
	return (ret);
}
