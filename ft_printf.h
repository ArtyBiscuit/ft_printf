#ifndef FT_PRINT_H
# define FT_PRINT_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_putnbr_base(unsigned long n, char *str);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_putchar(char str);
int	ft_printf(const char *str, ...);
#endif
