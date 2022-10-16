/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 03:26:40 by arforgea          #+#    #+#             */
/*   Updated: 2022/10/03 18:13:38 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_size;
	int		s2_size;
	char	*final_tab;

	if (!s1)
		return (NULL);
	s1_size = ft_strlen(s1) + 1;
	s2_size = ft_strlen(s2);
	final_tab = malloc(sizeof(char) * (s1_size + s2_size));
	if (!final_tab)
		return (NULL);
	ft_strlcpy(final_tab, s1, s1_size);
	ft_strlcat(final_tab, s2, s1_size + s2_size);
	return (final_tab);
}
