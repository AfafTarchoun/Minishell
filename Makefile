# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/21 21:10:29 by atarchou          #+#    #+#              #
#    Updated: 2022/08/28 02:34:11 by atarchou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc -Wall -Wextra -Werror 
FLAGS =  -lreadline
RL_FLAGS = -L /Users/atarchou/homebrew/opt/readline/lib -I /Users/atarchou/homebrew/opt/readline/include 
SRCS = parser/cmd.c\
		parser/env_expand.c\
		parser/env_expand1.c\
		parser/help_func.c\
		parser/help_func1.c\
		parser/lexer.c\
		parser/quotes.c\
		parser/redir.c\
		parser/token.c\
		parser/line_validation.c\
		parser/signals.c\
		parser/libft_func.c\
		parser/libft_func2.c\
		parser/free_func.c\
		parser/redir_quote_valid.c\
		parser/redir_quote_valid1.c\
		parser/collect_env.c\
		main.c\

$(NAME) : $(SRCS)
			@stty -echoctl
			$(CC) $(SRCS) $(RL_FLAGS) $(FLAGS) -o $(NAME) 

all : $(NAME)

clean :
		rm -rf $(NAME)

fclean :
		rm -rf minishell

re : fclean all

.PHONY : all clean fclean re
