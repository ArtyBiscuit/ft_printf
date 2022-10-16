/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 03:18:12 by arforgea          #+#    #+#             */
/*   Updated: 2022/10/05 03:25:17 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	cmp;
	unsigned int	s_size;

	if (!s || !f)
		return ;
	s_size = ft_strlen(s);
	cmp = 0;
	while (cmp < s_size)
	{
		f(cmp, s + cmp);
		cmp++;
	}
}
