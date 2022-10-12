/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:02:58 by arforgea          #+#    #+#             */
/*   Updated: 2022/10/12 19:31:39 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include <stdarg.h>

char	flags(const char *str, int index, int arg)
{
	if (!str || !arg)
		return (0);
	if (str[index] == arg)
		return (str[index + 1]);
	return (0);
}

/*
int	nb_flags(const char *str, int arg)
{
	int index;
	int nb_flags;

	index = 0;
	nb_flags = 0;
	if (!str)
		return (0);
	while (str[index])
	{
		if (str[index] == arg)
			nb_flags++;
		index++;
	}
	return (nb_flags);
}
*/

int ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		index;
	int		arg;

	arg = '%';
	index = 0;
	va_start(ptr, str);
	while (str[index])
	{
		if (flags(str, index, arg) == 's')
		{
			index += 2;
			ft_putstr_fd(va_arg(ptr, char*), 1);
		}
		if (flags(str, index, arg) == 'c')
		{
			index += 2;
			ft_putchar_fd(va_arg(ptr, int), 1);
		}
		if (flags(str, index, arg) == 'd')
		{
			index += 2;
			ft_putstr_fd(ft_itoa(va_arg(ptr, int)), 1);
		}
		else
			write(1, &str[index], 1);
		index++;
	}
	va_end(ptr);
	return (0);
}

int main(void)
{
	char	*str	= "OK";
	char	chr		= 'K';
	int		nbr		= 40;

	ft_printf("| str: %s | chr: %c | nbr: %d |", str, chr, nbr);
}
