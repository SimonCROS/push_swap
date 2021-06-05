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
	printf("└─────────┴─────────┘\n\033[%dA", size_a + size_b + 6);
	usleep(0.2 * 1000000);
}

void	replace_numbers(int **arr, int **rank, int size)
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

// void	start_chunk(int *a, int *b, int *sizea, int *sizeb, int size)
// {
// 	int	nearest;
// 	int	i;
// 	int	chunk_size;
// 	int	chunk_max;

// 	i = 0;
// 	chunk_size = size / 5;
// 	chunk_max = get_chunk_max()
// 	while ()
// 	{
// 	}	
// 	action(a, b, PUSH, B, sizea, sizeb);
// }

void	start_sort(int *a, int *b, int size)
{
	int	sizea;
	int	sizeb;

	sizea = size;
	sizeb = 0;
	print_stacks(a, b, sizea, sizeb);
	replace_numbers(&a, &b, size);
	print_stacks(a, b, sizea, sizeb);
	// while (*a)
	// {
	// 	start_chunk(a, b, &sizea, &sizeb, size);
	// 	print_stacks(a, b, sizea, sizeb);
	// }
	printf("\033[%dB", size + 6);
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
	return (ret);
}
