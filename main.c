#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	size = 0;

	int		nbr	= 42;
	unsigned int	ubr	= 84;
	char		*str	= NULL;
	char		chr	= '%';

	size = ft_printf("%c|%s|%p|%d|%i|%u|%x|%X|%%", chr, str, str, nbr, nbr, nbr, nbr, nbr);
	printf(" | %d\n", size);
	size = printf("%c|%s|%p|%d|%i|%u|%x|%X|%%", chr, str, str, nbr, nbr, nbr, nbr, nbr);
	printf(" | %d\n", size);
}
