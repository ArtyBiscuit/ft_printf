/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:02:58 by arforgea          #+#    #+#             */
/*   Updated: 2022/10/24 19:07:48 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

static char	flags(const char *str, int index)
{
	char	flags;

	if (str[index] == '%')
	{
		flags = str[index + 1];
		return (flags);
	}
	return (0);
}

static int	ft_putlast_addrstr(va_list ptr)
{
	unsigned long long	tmp;
	int					size;

	size = 2;
	tmp = va_arg(ptr, unsigned long long);
	if (!tmp)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	size += ft_putnbr_base(tmp, "0123456789abcdef");
	return (size);
}

static void	ft_print_flags(int *index, const char *str, va_list ptr, int *size)
{
	if (flags(str, *index) == 's')
		*size += ft_putstr(va_arg(ptr, char *));
	else if (flags(str, *index) == 'c')
		*size += ft_putchar(va_arg(ptr, int));
	else if (flags(str, *index) == 'd')
		*size += ft_putnbr(va_arg(ptr, int));
	else if (flags(str, *index) == 'p')
		*size += ft_putlast_addrstr(ptr);
	else if (flags(str, *index) == 'i')
		*size += ft_putnbr(va_arg(ptr, int));
	else if (flags(str, *index) == 'u')
		*size += ft_putnbr_base(va_arg(ptr, unsigned int), "0123456789");
	else if (flags(str, *index) == 'x')
		*size += ft_putnbr_base(va_arg(ptr, unsigned int), "0123456789abcdef");
	else if (flags(str, *index) == 'X')
		*size += ft_putnbr_base(va_arg(ptr, unsigned int), "0123456789ABCDEF");
	else if (flags(str, *index) == '%')
		*size += ft_putchar('%');
	else
	{
		*size += ft_putchar('%');
		*size += ft_putchar(flags(str, *index));
	}
}

static void	ft_chek_flags(int *index, const char *str, va_list ptr, int *size)
{
	if (str[*index] != '%')
	{
		*size += ft_putchar(str[*index]);
		*index += 1;
		return ;
	}
	ft_print_flags(index, str, ptr, size);
	*index += 2;
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		index;
	int		final_size;

	index = 0;
	final_size = 0;
	va_start(ptr, str);
	while (str[index])
		ft_chek_flags(&index, str, ptr, &final_size);
	va_end(ptr);
	return (final_size);
}
