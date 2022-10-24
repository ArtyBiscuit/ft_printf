/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:15:41 by arforgea          #+#    #+#             */
/*   Updated: 2022/10/24 19:16:02 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_putnbr_base(unsigned long n, char *str);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_putchar(char str);
int	ft_printf(const char *str, ...);
#endif
