/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 04:21:12 by arforgea          #+#    #+#             */
/*   Updated: 2022/10/10 15:36:58 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_tab_size(long nbr)
{
	int	size;

	size = 0;
	if (nbr <= 0)
	{
		nbr = -nbr;
		size = 1;
	}
	while (nbr)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

static void	ft_put_int(char *f_tab, int index, long nbr)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		f_tab[0] = '-';
		f_tab++;
		index--;
	}
	while (index >= 0)
	{
		f_tab[index] = nbr % 10 + '0';
		nbr /= 10;
		index--;
	}
}

char	*ft_itoa(int n)
{
	char	*f_tab;
	int		size;

	size = ft_tab_size((long) n);
	f_tab = ft_calloc(1, size + 1);
	if (!f_tab)
		return (NULL);
	ft_put_int(f_tab, size - 1, (long) n);
	return (f_tab);
}
