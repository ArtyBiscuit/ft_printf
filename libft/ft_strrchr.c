/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:43:18 by arforgea          #+#    #+#             */
/*   Updated: 2022/10/10 14:26:20 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*src;
	int		cmp;

	src = (char *) s;
	cmp = ft_strlen(src) + 1;
	if (!src)
		return (src);
	while (cmp)
	{
		cmp--;
		if (src[cmp] == (char)c)
			return (src + cmp);
	}
	return (NULL);
}
