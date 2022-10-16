/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:20:07 by arforgea          #+#    #+#             */
/*   Updated: 2022/10/10 15:37:58 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_nb_line(char const *str, char c)
{
	int	i;
	int	nb_line;

	i = 0;
	nb_line = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			nb_line++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (nb_line);
}

static int	ft_nb_char(char const *str, char c, int *index)
{
	int	nb_char;

	nb_char = 0;
	while (str[*index] && str[*index] == c)
		(*index)++;
	while (str[*index] && str[*index] != c)
	{
		(*index)++;
		nb_char++;
	}
	return (nb_char);
}

char	**ft_split(char const *s, char c)
{
	char	**f_tab;
	int		index;
	int		nb_char;
	int		nb_line;
	int		i;

	if (!s)
		return (NULL);
	index = 0;
	nb_line = ft_nb_line(s, c);
	f_tab = malloc(sizeof(char *) * (nb_line + 1));
	if (!f_tab)
		return (NULL);
	i = 0;
	while (i != nb_line)
	{
		nb_char = ft_nb_char(s, c, &index);
		f_tab[i] = ft_calloc(1, nb_char + 1);
		ft_strlcpy(f_tab[i], s + (index - nb_char), nb_char + 1);
		nb_char = 0;
		i++;
	}
	f_tab[i] = NULL;
	return (f_tab);
}
