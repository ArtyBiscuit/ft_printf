#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	size = 0;

	int		nbr	= -56849;
	unsigned int	ubr	= -65894;
	char		*str	= "yo les amis c'est david la farge  le FDP!";
	char		chr	= '%';

	size = ft_printf("%c|%s|%p|%d|%i|%u|%x|%X|%%", chr, str, str, nbr, nbr, nbr, nbr, nbr);
	printf(" | %d\n", size);
	size = printf("%c|%s|%p|%d|%i|%u|%x|%X|%%", chr, str, str, nbr, nbr, nbr, nbr, nbr);
	printf(" | %d\n", size);
}
