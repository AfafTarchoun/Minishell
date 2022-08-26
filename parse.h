/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:49:34 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/26 21:14:51 by atarchou         ###   ########.fr       */
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

typedef struct s_env
{
	int	exit_value;
}			t_env;

typedef struct s_exec
{
	int		in;
	int		args;
	t_env	env;
	char	**envp;
	char	**command;
	int		pipe_flag;
	int		pipe_count;
	int		input_flag;
	int		error_flag;
	int		input_count;
	int		append_flag;
	int		initial_flag;
	int		heredoc_flag;
	int		append_count;
	int		heredoc_count;
	int		redirecion_flag;
	int		redirection_count;
	int		pipe_index;
	int		err_flag;
}	t_exec;

typedef struct s_lexer
{
	char			c;
	int				i;
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
	SPECIALCHAR,
	EQUALS,
	W_SPACE,
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
t_cmd	*create_lst_cmd(t_lexer *lexer, t_exec *exec);

/************* env_expand.c ************/

int		get_count(char *str, char *find, int *io);
int		get_env_size(char *str);
char	*find_str_env(char *str);
char	*replace_env(char *str, char *find, char *replace);
char	*expand_env_word(char *str, char quote, t_exec *exec);

/************* env_expand1.c ************/

char	*ft_expand(char *expand, char **envp);
char	*expand_env(char *str, char quote, t_exec *exec);
t_token	*lx_collect_env(t_lexer *lexer, t_exec *exec);

/************* help_func.c ************/

void	*ft_realloc(void *ptr, size_t size);
int		find_char_index(char *str, char c);
char	*remove_char(char *str, char charToRemmove);
int		count_words(char *str);
void	delete_node(t_cmd **head, t_cmd *prev);
char	*replace_char(char *str, char ori, char rep);
void	collect_process(char **str, char **value, t_lexer *lexer);

/************* lexer.c ************/

t_lexer	*init_lx(char *str);
void	lx_advance(t_lexer *lexer);
void	lx_skip_ws(t_lexer *lexer);
char	*lx_getchar_as_str(t_lexer *lexer);
t_token	*lx_collect_str(t_lexer *lexer);

/************* quotes.c ************/

t_token	*lx_collect_quote(t_lexer *lexer, char quote, t_exec *exec);
char	*append_quotes(char *value, char *str);
char	*allocate(char *value, char *str);

/************* redir.c ************/

t_token	*lx_collect_redirs(t_lexer *lexer, char redir);
int		is_op(char c);

/************* signals.c ************/

void	ft_putchar_fd(char c, int fd);
void	handle_signals(int sig);
void	ft_signals(void);

/************* token.c ************/

t_token	*init_token(int type, char *value, char quote);
t_token	*lx_advance_wtok(t_lexer *lexer, t_token *token);
t_token	*lx_get_next_tok(t_lexer *lexer, t_exec *exec);
t_token	*lx_collect_spaces(t_lexer *lexer);
t_token	*lx_handle_operations(t_lexer *lexer);
void	manage_tokens(t_cmd **cmd_old);

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
int		ft_strcmp(char *s1, char *s2);

/************* free_func.c ************/

void	free_cmd(t_cmd **cmd);

/************* redir_quote_valid.c ************/

void	ignore_inside_quotes(char str, int *value, int *flag);
int		validate_pipes(char *str);
int		check_line_correctness(char *str);

/************* redir_quote_valid1.c ************/

int		validate_repetition(char *str, char redir1, char redir2);
int		validate_redirs(char *str);
int		validate_quote_type(char *str, char quote1, char quote2);
int		validate_quotes(char *str);
int		validate_line(char *str);

/************* parsing.c ************/

void	ft_get_env(t_exec *exec, char **env);
int		ft_count_elements(char **str);
char	*ft_mystrdup(char *s1, int flag);
char	*ft_mystrdu_norm(char *str, char *s1, int i, int j);
char	*ft_get_expand_env(char *str);
int		ft_find_variable_index(char *str, char c);
int		ft_find_last_character(char *str, char c);
#endif
