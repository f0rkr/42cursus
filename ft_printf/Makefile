# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mashad <mashad@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 16:39:51 by mashad            #+#    #+#              #
#    Updated: 2019/11/16 14:44:46 by mashad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
AR=ar
FLAGS = -Wall -Werror -Wextra
SRC = ft_isdigit.c ft_strlen.c ft_printf.c ft_putptr_fd.c ft_putnbr_fdret.c ft_putchar_fdret.c ft_printp.c ft_puthexa_fd.c ft_porc.c ft_printint.c ft_putuns_fd.c ft_putnbr_m.c ft_returnfun.c gather_data.c point_exist.c ft_putnchar.c ft_numlen.c ft_printstr.c ft_putnstr.c ft_printhexa.c ft_putstrrev_fd.c ft_hexalen.c ft_printchar.c ft_printuns.c ft_putuns_m.c

all:$(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	$(AR) rsc $(NAME) *.o
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re:fclean all
