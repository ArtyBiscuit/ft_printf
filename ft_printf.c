/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:02:58 by arforgea          #+#    #+#             */
/*   Updated: 2022/10/24 15:25:57 by arforgea         ###   ########.fr       */
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
	unsigned long tmp;

	tmp = va_arg(ptr, unsigned long);
	if (!tmp)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ft_putnbr_base(tmp, "0123456789abcdef");
	return (14);
}

static int	ft_print_flags(int *index, const char *str, va_list ptr, int arg)
{
	int	size;
	char	flag;

	size = 0;
	flag = flags(str, *index, arg);
	if (flag == 's')
		size += ft_putstr(va_arg(ptr, char *));
	else if (flag == 'c')
		size += ft_putchar(va_arg(ptr, int));
	else if (flag == 'd')
		size += ft_putnbr(va_arg(ptr, int));
	else if (flag == 'p')
		size += ft_putlast_addrstr(ptr);
	else if (flag == 'i')
		size += ft_putnbr(va_arg(ptr, int));
	else if (flag == 'u')
		size += ft_putnbr_base(va_arg(ptr, unsigned int), "0123456789");
	else if (flag == 'x')
		size += ft_putnbr_base(va_arg(ptr, unsigned int), "0123456789abcdef");
	else if (flag == 'X')
		size += ft_putnbr_base(va_arg(ptr, unsigned int), "0123456789ABCDEF");
	else if (flag == '%')
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
