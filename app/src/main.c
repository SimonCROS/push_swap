#include "push_swap/ps_common.h"
#include "push_swap/ps_app.h"

int	main(int argc, char *argv[])
{
	t_named_stack	a;
	t_named_stack	b;
	int				ret;

	if (argc == 1)
		return (EXIT_SUCCESS);
	a.super = init_numbers(argv + 1, argc - 1, &b.super);
	a.name = A;
	b.name = B;
	ret = EXIT_SUCCESS;
	if (!a.super.array || !b.super.array || !is_valid(&a.super))
		ret = EXIT_FAILURE;
	else if (!array_is_sorted(a.super.array, a.super.size))
		start_sort(&a, &b);
	free(a.super.array);
	free(b.super.array);
	if (ret == EXIT_FAILURE)
		ft_putendl_fd("Error", 2);
	return (ret);
}
