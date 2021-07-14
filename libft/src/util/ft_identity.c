#include "libft.h"

static void	*ft_identity_funct(void *input)
{
	return (input);
}

t_function	ft_identity(void)
{
	return (&ft_identity_funct);
}
