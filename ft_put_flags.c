/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:40:54 by arforgea          #+#    #+#             */
/*   Updated: 2022/10/24 19:14:18 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

int	ft_putchar(char str)
{
	write(1, &str, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_base(unsigned long long n, char *str)
{
	unsigned int	base;
	int				size;

	size = 0;
	base = ft_strlen(str);
	if (n >= base)
	{
		size += ft_putnbr_base(n / base, str);
		size += ft_putnbr_base(n % base, str);
	}
	if (n < base)
		size += ft_putchar(str[n]);
	return (size);
}

int	ft_putnbr(int n)
{
	int				size;

	size = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		size += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		size += ft_putnbr(n / 10);
		size += ft_putnbr(n % 10);
	}
	if (n < 10)
	{
		n += '0';
		size += ft_putchar(n);
	}
	return (size);
}
