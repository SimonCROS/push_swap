#include "push_swap.h"

#include <stdio.h>//

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
			printf("% 7d", a[i]);
		else
			printf("%7s", " ");
		printf(" │ ");
		if (i < size_b)
			printf("% 7d", b[i]);
		else
			printf("%7s", " ");
		printf(" │\n");
		i++;
	}
	printf("└─────────┴─────────┘\n");
}

void	start_sort(int *a, int *b, int size)
{
	print_stacks(a, b, size, 0);
	arr_push(a, 1, &size);
	print_stacks(a, b, size, 0);
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
