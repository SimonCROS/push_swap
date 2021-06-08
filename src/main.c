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

void	print_stacks(int *a, int *b, int size_a, int size_b)
{
	int	i;

	i = 0;
	printf("┌───────────────────┐\n");
	printf("│  \033[1mStacks debugger\033[0m  │\n");
	printf("╞═════════╤═════════╡\n");
	printf("│ Stack A │ Stack B │\n");
	printf("├─────────┼─────────┤\n");
	while (i < size_a + size_b)
	{
		printf("│ ");
		if (i < size_a)
			printf("%7d", a[i]);
		else
			printf("%7s", " ");
		printf(" │ ");
		if (i < size_b)
			printf("%7d", b[i]);
		else
			printf("%7s", " ");
		printf(" │\n");
		i++;
	}
	printf("└─────────┴─────────┘\n");
	printf("\033[%dA", size_a + size_b + 6);
	usleep(0.2 * 1000000);
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
	int	i;
	int	j;

	half = *sizea / 2;
	i = 0;
	while (i < chunk_max && *sizea)
	{
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
			if (a[j] < chunk_max && *sizea - 1 - j < nearest)
			{
				nearest = -j;
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
		i++;
	}
}

void	start_sort(int *a, int *b, int size)
{
	int	chunk_step;
	int	chunk_max;
	int	sizea;
	int	sizeb;

	sizea = size;
	sizeb = 0;
	chunk_step = size / 5;
	// printf("%d - %d\n", size, chunk_step);
	chunk_max = chunk_step;
	rank_array(&a, &b, size);
	while (sizea)
	{
		make_chunk(a, b, &sizea, &sizeb, chunk_max);
		chunk_max += chunk_step;
	}
	// printf("\033[%dB", size + 6);
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
