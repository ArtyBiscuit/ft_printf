# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arforgea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 14:07:21 by arforgea          #+#    #+#              #
#    Updated: 2022/10/10 15:11:12 by arforgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_itoa.c ft_striteri.c ft_strmapi.c ft_split.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_atoi.c ft_calloc.c ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_strrchr.c ft_strdup.c ft_strchr.c ft_strncmp.c ft_memcmp.c ft_memchr.c ft_tolower.c ft_toupper.c ft_memmove.c ft_memcpy.c ft_bzero.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_memset.c ft_strlen.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_BONUS = ft_lstmap_bonus.c ft_lstiter_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)
.c.o:
	$(CC) $(CFLAGS) $< -c -o $@
clean:
	rm -rf $(OBJ) $(OBJ_BONUS)
fclean:	clean
	rm -rf $(NAME)
re: fclean all
bonus: $(OBJ_BONUS) $(OBJ)
	ar -rc $(NAME) $(OBJ_BONUS) $(OBJ)
.PHONY: all clean fclean re bonus
