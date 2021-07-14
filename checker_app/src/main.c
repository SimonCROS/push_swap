#include "push_swap/ps_common.h"
#include "push_swap/ps_checker.h"

#include <stdio.h>

int start_listen(t_stack *a, t_stack *b)
{
	t_read_status	result;
	char			*line;
	int				reading;

	result = READ_SUCCESS;
	reading = 0;
	while (result == READ_SUCCESS)
	{
		reading++;
		result = get_next_line(0, &line);
		if (result == READ_ERROR)
			return (EXIT_FAILURE);
		if (result == READ_EOF)
		{
			if (*line)
				result = READ_ERROR;
			free(line);
			break ;
		}
		if (ft_str_equals(line, "rra"))
			action_on(a, b, REVERSE_ROTATE);
		else if (ft_str_equals(line, "rrb"))
			action_on(b, a, REVERSE_ROTATE);
		else if (ft_str_equals(line, "rrr"))
		{
			action_on(a, b, REVERSE_ROTATE);
			action_on(b, a, REVERSE_ROTATE);
		}
		else if (ft_str_equals(line, "ra"))
			action_on(a, b, ROTATE);
		else if (ft_str_equals(line, "rb"))
			action_on(b, a, ROTATE);
		else if (ft_str_equals(line, "rr"))
		{
			action_on(a, b, ROTATE);
			action_on(b, a, ROTATE);
		}
		else if (ft_str_equals(line, "sa"))
			action_on(a, b, SWAP);
		else if (ft_str_equals(line, "sb"))
			action_on(b, a, SWAP);
		else if (ft_str_equals(line, "ss"))
		{
			action_on(a, b, SWAP);
			action_on(b, a, SWAP);
		}
		else if (ft_str_equals(line, "pa"))
			action_on(a, b, PUSH);
		else if (ft_str_equals(line, "pb"))
			action_on(b, a, PUSH);
		else
			result = READ_ERROR;
		free(line);
	}
	if (result == READ_ERROR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
	else
	{
		ret = start_listen(&a, &b);
		if (ret == EXIT_SUCCESS)
		{
			if (b.size == 0 && array_is_sorted(a.array, a.size))
				ft_putendl("OK");
			else
				ft_putendl("KO");
		}
	}
	free(a.array);
	free(b.array);
	if (ret == EXIT_FAILURE)
		ft_putendl_fd("Error", 2);
	return (ret);
}
