/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:40:47 by arforgea          #+#    #+#             */
/*   Updated: 2022/10/09 18:00:17 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	char	*str;

	str = (char *) big;
	i = 0;
	if (little[0] == '\0' || big == little)
		return (str);
	while (len || !little[i])
	{
		if (little[i] == '\0')
			return (str - i);
		if (*str == '\0')
			return (0);
		i++;
		if (*str != little[i - 1])
		{
			str -= i - 1;
			len += i - 1;
			i = 0;
		}
		str++;
		len--;
	}
	return (0);
}
