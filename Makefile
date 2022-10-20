# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arforgea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 14:07:21 by arforgea          #+#    #+#              #
#    Updated: 2022/10/20 13:53:37 by arforgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_put_flags.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	mv libft/libft.a .
	mv libft.a libftprintf.a
	ar -rc $(NAME) $(OBJ)
.c.o:
	$(CC) $(CFLAGS) $< -c -o $@
clean:
	make -C $(LIBFT) clean
	rm -rf $(OBJ)
fclean:	clean
	make -C $(LIBFT) fclean
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re
