/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:02:58 by arforgea          #+#    #+#             */
/*   Updated: 2022/10/15 18:19:25 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include <stdarg.h>
int ft_putnbr_base(unsigned long n, char *str);
int ft_putstr(char *str);
int ft_putchar(char str);

char	flags(const char *str, int index, int arg)
{
	char flags;

	if (str[index] == arg)
	{
		flags = str[index + 1];
		return (flags);
	}
	return (0);
}

void	ft_putlast_addrstr(va_list ptr)
{
	int index;

	write(1, "0x", 2);
	ft_putnbr_base(va_arg(ptr, unsigned long), "0123456789abcdef");
}

void	ft_print_flags(int *index, const char *str, va_list ptr, int arg)
{
	if (str[*index] != arg)
	{
		write(1, &str[*index], 1);
		*index += 1;
		return ;
	}
	else if (flags(str, *index, arg) == 's')
		ft_putstr(va_arg(ptr, char*));
	else if (flags(str, *index, arg) == 'c')
		ft_putchar(va_arg(ptr, int));
	else if (flags(str, *index, arg) == 'd')
		ft_putnbr_fd(va_arg(ptr, int), 1);
	else if (flags(str, *index, arg) == 'p')
		ft_putlast_addrstr(ptr);
	else if (flags(str, *index, arg) == 'i')
		ft_putnbr_fd(va_arg(ptr, int), 1);
	else if (flags(str, *index, arg) == 'u')
		ft_putnbr_fd(va_arg(ptr, int), 1);
	else if (flags(str, *index, arg) == 'x')
        ft_putnbr_base(va_arg(ptr, int), "0123456789abcdef");
	else if (flags(str, *index, arg) == 'X')
		ft_putnbr_base(va_arg(ptr, int), "0123456789ABCDEF");
	else if (flags(str, *index, arg) == '%')
		ft_putchar_fd('%', 1);
	*index += 2;
}
int ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		index;
	int		arg;

	arg = '%';
	index = 0;
	va_start(ptr, str);
	while (str[index])
		ft_print_flags(&index, str, ptr, arg);
	va_end(ptr);
	return (0);
}


#include <stdio.h>
int main(void)
{
	char	*str	= "OK";
	char	chr		= 'K';
	int		nbr		= 255;
	unsigned int nbu = 55;

	printf("%d", printf("%s,%c,%d,%p,%i,%u,%x,%X,%%,\n", str, chr, nbr, str, nbr, nbu, nbr, nbr));
	ft_printf("%s,%c,%d,%p,%i,%u,%x,%X,%%,\n", str, chr, nbr, str, nbr, nbu, nbr, nbr);
}
