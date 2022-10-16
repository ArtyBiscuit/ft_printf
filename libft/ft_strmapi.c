/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:18:48 by arforgea          #+#    #+#             */
/*   Updated: 2022/10/05 03:16:12 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*f_tab;
	unsigned int	s_size;
	unsigned int	cmp;

	cmp = 0;
	if (!s || !f)
		return (NULL);
	s_size = ft_strlen(s) + 1;
	f_tab = ft_calloc(1, s_size);
	if (!f_tab)
		return (NULL);
	while (cmp < s_size - 1)
	{
		f_tab[cmp] = f(cmp, s[cmp]);
		cmp++;
	}
	return (f_tab);
}
