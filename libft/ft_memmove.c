/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:35:24 by arforgea          #+#    #+#             */
/*   Updated: 2022/09/30 19:02:00 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_s;
	unsigned char	*tmp_d;
	size_t			i;

	tmp_s = (unsigned char *) src;
	tmp_d = (unsigned char *) dest;
	i = 0;
	if (!tmp_s && !tmp_d)
		return (dest);
	while (n != i)
	{
		if (tmp_s >= tmp_d)
		{
			tmp_d[i] = tmp_s[i];
			i++;
		}
		else
		{
			n--;
			tmp_d[n] = tmp_s[n];
		}
	}
	return (dest);
}
