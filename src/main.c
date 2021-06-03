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
	*stack2 = malloc(size * sizeof(int));
	result = malloc(size * sizeof(int));
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

int main(int argc, char *argv[])
{
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
	if (!a || !b)
	{
		free(a);
		free(b);
		return (EXIT_FAILURE);
	}
	int i;
	i = 0;
	while (i < size)
	{
		printf("%d\n", a[i]);
		i++;
	}
	free(a);
	free(b);
	return (EXIT_SUCCESS);
}
