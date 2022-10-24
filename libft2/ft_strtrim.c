/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:22:34 by arforgea          #+#    #+#             */
/*   Updated: 2022/10/10 16:12:12 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_stedstr(const char *str, const char *set, int index)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (str[index] == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*final_tab;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	start = 0;
	while (ft_stedstr(s1, set, start))
		start++;
	end = ft_strlen(s1);
	while (ft_stedstr(s1, set, end - 1))
		end--;
	final_tab = ft_substr(s1, start, end - start);
	return (final_tab);
}
