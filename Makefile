# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 20:16:21 by atarchou          #+#    #+#              #
#    Updated: 2022/10/03 23:27:42 by atarchou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc -Wall -Wextra -Werror 
FLAGS =  -lreadline 
RL_FLAGS = -L /Users/atarchou/homebrew/opt/readline/lib -I /Users/atarchou/homebrew/opt/readline/include

LIBFT_DIR = libftt
LIB = libftt/libft.a
PF = ft_printf/libftprintf.a
GNL = gnl/get_next_line.c gnl/get_next_line_utils.c

SRC = srcs/b_env.c\
	  	srcs/b_export.c \
	 	 srcs/b_export2.c \
	 	srcs/b_echo.c \
	  srcs/b_unset.c \
	  srcs/b_cd.c \
	  srcs/b_pwd.c \
	  srcs/b_exit.c \
	  srcs/execution.c \
	  srcs/builtin_ops.c \
	  srcs/file_handlers.c \
	  srcs/accessibility.c \
	  gnl/get_next_line.c \
	  gnl/get_next_line_utils.c \
	  srcs/env.c\
	  srcs/env2.c\
	  srcs/env3.c\
	srcs/help_func.c\
	srcs/help_fucn2.c\
	srcs/lexer.c\
	srcs/quotes.c\
	srcs/redir.c\
	srcs/token.c\
	srcs/tokens1.c\
	srcs/cmd.c\
	srcs/cmd2.c\
	srcs/lst_token_nw.c\
	srcs/line_validation.c\
	srcs/libft_func2.c\
	srcs/free_fucn.c\
	srcs/free_func.c\
	srcs/input_src.c\
	srcs/redir_quote_valid.c\
	srcs/redir_quote_valid1.c\
	srcs/expansion.c\
	srcs/files.c\
	srcs/files1.c\
	srcs/files2.c\
	srcs/utils.c \
	srcs/main.c \
	srcs/heredoc.c \
	srcs/herdoc2.c \
	srcs/helpers.c \
	srcs/signals.c \

$(NAME) : $(SRC)
			@stty -echoctl
			$(CC) $(SRC) $(RL_FLAGS) $(FLAGS) $(LIB) $(PF)  -o $(NAME) 

all : $(NAME)

clean :
		rm -rf $(NAME)

fclean :
		rm -rf minishell

re : fclean all

.PHONY : all clean fclean re
