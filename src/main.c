#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_list	a;
	t_list	b;

	if (argc == 1)
		return (EXIT_SUCCESS);
	if (argc == 2)
		a = as_listf(ft_split(argv[1]), free);
	else
		a = as_list(argv + 1, NULL);
	if (!a)
		return (EXIT_FAILURE);
	clst_map_in(a, ft_atoip_full, NULL);
	return (EXIT_SUCCESS);
}
