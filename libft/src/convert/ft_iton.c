#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_intlen(n) + 1;
	str = malloc(len);
	if (!str)
		return (NULL);
	str[len] = 0;
	return (ft_itoa_to(n, str));
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_uintlen(n) + 1;
	str = malloc(len);
	if (!str)
		return (NULL);
	str[len] = 0;
	return (ft_uitoa_to(n, str));
}

char	*ft_itohex(unsigned int n, int prefix)
{
	int		len;
	char	*str;

	len = ft_intlen_hex(n, prefix, 0) + 1;
	str = malloc(len);
	if (!str)
		return (NULL);
	str[len] = 0;
	return (ft_itohex_to(n, str, prefix));
}

char	*ft_itooctal(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_intlen_octal(n) + 1;
	str = malloc(len);
	if (!str)
		return (NULL);
	str[len] = 0;
	return (ft_itooctal_to(n, str));
}
