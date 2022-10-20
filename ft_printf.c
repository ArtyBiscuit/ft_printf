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
#include "ft_printf.h"
#include <stdarg.h>

static char	flags(const char *str, int index, int arg)
{
	char	flags;

	if (str[index] == arg)
	{
		flags = str[index + 1];
		return (flags);
	}
	return (0);
}

static int	ft_putlast_addrstr(va_list ptr)
{
	write(1, "0x", 2);
	ft_putnbr_base(va_arg(ptr, unsigned long), "0123456789abcdef");
	return (14);
}

static int	ft_print_flags(int *index, const char *str, va_list ptr, int arg)
{
	int	size;
	char	flags;

	size = 0;
	flags = flags(str, *index, arg);
	if (flags == 's')
		size += ft_putstr(va_arg(ptr, char *));
	else if (flags == 'c')
		size += ft_putchar(va_arg(ptr, int));
	else if (flags == 'd')
		size += ft_putnbr_base(va_arg(ptr, int), "0123456789");
	else if (flags == 'p')
		size += ft_putlast_addrstr(ptr);
	else if (flags == 'i')
		size += ft_putnbr_base(va_arg(ptr, int), "0123456789");
	else if (flags == 'u')
		size += ft_putnbr_base(va_arg(ptr, int), "0123456789");
	else if (flags == 'x')
		size += ft_putnbr_base(va_arg(ptr, int), "0123456789abcdef");
	else if (flags == 'X')
		size += ft_putnbr_base(va_arg(ptr, int), "0123456789ABCDEF");
	else if (flags == '%')
		size += ft_putchar('%');
	return (size);
}

static int	ft_chek_flags(int *index, const char *str, va_list ptr, int arg)
{
	int	size;

	size = 0;
	if (str[*index] != arg)
	{
		size += ft_putchar(str[*index]);
		*index += 1;
		return (size);
	}
	size += ft_print_flags(index, str, ptr, arg);
	*index += 2;
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		index;
	int		arg;
	int		final_size;

	arg = '%';
	index = 0;
	final_size = 0;
	va_start(ptr, str);
	while (str[index])
		final_size += ft_chek_flags(&index, str, ptr, arg);
	va_end(ptr);
	return (final_size);
}
