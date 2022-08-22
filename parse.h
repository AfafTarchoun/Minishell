/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:49:34 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/22 10:06:33 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <unistd.h>

typedef struct s_lexer
{
	char			c;
	unsigned int	i;
	char			*str;
}				t_lexer;

typedef enum e_type
{
	WORD,
	REDIRIN,
	REDIROUT,
	APPEND,
	HEREDOC,
	PIPE,
	EQUALS
}				t_type;

typedef struct s_token
{
	int				type;
	char			*value;
	char			quote;
}				t_token;

typedef struct s_cmd
{
	struct s_cmd	*next;
	t_token			*tok;
}				t_cmd;

/************* cmd.c ************/

t_cmd	*init_cmd(t_token *tok);
t_cmd	*create_lst_cmd(t_lexer *lexer);

/************* env_expand.c ************/

char	*expand_env(char *str, char quote);
t_token	*lx_collect_env(t_lexer *lexer);
char	*find_str_env(char *str);
char	*replace_env(char *str, char *find, char *replace);
char	*expand_env_word(char *str, char quote);

/************* help_func.c ************/

void	*ft_realloc(void *ptr, size_t size);
int		find_char_index(char *str, char c);
char	*remove_char(char *str, char charToRemmove);
int		count_words(char *str);
void	delete_node(t_cmd **head, t_cmd *prev);

/************* lexer.c ************/

t_lexer	*init_lx(char *str);
void	lx_advance(t_lexer *lexer);
void	lx_skip_ws(t_lexer *lexer);
char	*lx_getchar_as_str(t_lexer *lexer);
t_token	*lx_collect_str(t_lexer *lexer);

/************* quotes.c ************/

t_token	*lx_collect_quote(t_lexer *lexer, char quote);
char	*append_quotes(char *value, char *str);
void	fix_quotes(t_cmd **cmd_old);

/************* redir.c ************/

t_token	*lx_collect_redirs(t_lexer *lexer, char redir);

/************* signals.c ************/

void	ft_putchar_fd(char c, int fd);
void	handle_signals(int sig);
void	ft_signals(void);

/************* token.c ************/

t_token	*init_token(int type, char *value, char quote);
t_token	*lx_advance_wtok(t_lexer *lexer, t_token *token);
t_token	*lx_get_next_tok(t_lexer *lexer);
t_token	*lx_collect_spaces(t_lexer *lexer);

/************* libft_func.c ************/

int		ft_strlen(char *str);
char	*ft_strdup(char *src);
void	*ft_memcpy(void *str1, const void *str2, int n);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strcpy(char *dest, char *src);

/************* libft_func2.c ************/

int		ft_isalnum(int s);
int		ft_isspace(int c);
char	*ft_strcat(char *dest, char *src);

#endif