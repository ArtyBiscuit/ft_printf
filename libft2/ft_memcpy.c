/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:32:39 by arforgea          #+#    #+#             */
/*   Updated: 2022/10/10 14:50:03 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*tmp_s;
	char	*tmp_d;

	tmp_s = (char *) src;
	tmp_d = (char *) dest;
	while ((tmp_s || tmp_d) && n)
	{
		n--;
		tmp_d[n] = tmp_s[n];
	}
	return (dest);
}
