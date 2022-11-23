# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 16:56:34 by atarchou          #+#    #+#              #
#    Updated: 2021/12/04 14:48:09 by atarchou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =  ft_printf.c\
		ft_print_address.c\
		ft_print_hexa_address.c\
		ft_print_hexa_lower.c\
		ft_print_hexa_upper.c\
		ft_putchar.c\
		ft_putnbr.c\
		ft_putnbr_unsigned.c\
		ft_putstr.c

CC = gcc 
FLAGS = -Wall -Wextra -Werror	
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@
		ar rc $(NAME) $@
		ranlib $(NAME)
clean :
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
