/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:18:30 by achahdan          #+#    #+#             */
/*   Updated: 2022/10/03 23:27:18 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libftt/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include <limits.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <signal.h>

// enums
typedef enum e_type {
	OTHER,
	INF,
	OUTF,
	APPF,
	HRDOC,
	PIPE,
	WSPACE
}			t_type;

enum e_f_mode
{
	NEW,
	APP,
	IN
};

enum e_input
{
	INFILE,
	HEREDOC,
	STDIN
};

enum e_loc
{
	PROMPT,
	HDOC,
	EXEC
};

//structures

typedef struct s_lexer
{
	char			c;
	unsigned int	i;
	char			*str;
}				t_lexer;

typedef struct s_name
{
	char			*name;
	enum e_f_mode	f_mode;
	struct s_name	*next;
}				t_name;

typedef struct s_values
{
	int		type;
	char	*value;
	char	quote;
}				t_values;

typedef struct s_cmd
{
	char			*cmd;
	t_name			*files;
	int				out_file;
	int				in_file;
	t_name			*heredoc_lst;
	char			*heredoc_path;
	int				heredoc;
	enum e_input	input_source;
	t_name			*args_lst;
	char			**args;
	struct s_cmd	*next;
}				t_cmd;

typedef struct s_env
{
	char			*var;
	char			*value;
	struct s_env	*next;
}				t_env;

typedef struct s_token
{
	char			*value;
	int				type;
	char			quote;
	int				file;
	struct s_token	*next;
}				t_token;

typedef struct s_data
{
	char		**env;
	t_env		*env_lst;
	t_cmd		*cmds;
	int			exit_code;
	t_token		*tok;
	t_token		*no_ws;
	int			pipe_found;
	enum e_loc	loc;
	int			cmd_count;
	int			last_cmd_returned;
	int			sig_caught;
}				t_data;

//global variable
t_data	g_data;

// prototypes
int			ft_perror(char *name, char *error, int free);

// BUILTINS 
t_env		*clone_list(void);
void		find_smallest(t_env *env);
int			sv(t_env *env, char *var);
char		**split_arg(char *arg);
void		pwd(void);
void		env(void);
void		print_export(void);
void		export(t_env *env, char **args);
void		free_2d_array(char **tab);
void		echo(t_cmd *cmd);
void		fill_env(void);
void		print_2d(void);
void		unset(t_cmd *cmd);
void		search_and_unset(char *str);
void		cd(t_cmd *cmd);
void		ft_exit(t_cmd *cmd);
void		add_node(t_env **lst, char *var, char *value);
void		replace_val(t_env *env, int index, char *new_value, int flag);
int			sv(t_env *env, char *var);
int			co(char *str);

// EXECUTION
int			open_files(t_cmd *cmd);
int			run_one_builtin(void);
int			ft_execute(t_cmd *cmd);
int			is_builtin(t_cmd *cmd);
void		exec_builtin(t_cmd *cmd);
char		*check_path(char *cmd, t_env *env);
int			cmd_lst_len(t_cmd *cmds);

// SIGNALS
void		sig_int_handler(int sig);
void		sig_quit_handler(int sig);

// dyalk 

int			get_env_size(char *str);
char		*find_str_env(char *str);
int			get_count(char *str, char *find, int *io);
char		*replace_env(char *str, char *find, char *replace);
char		*expand_env_word(char *str, char quote, t_env *env_lst);
void		handle_env_replace(char **str, char *env, int flag, t_env *env_lst);
char		*handle_num_env(char *str);
void		handle_num_replace(char **str, char *tmp, char *env);
char		*expand_env(char *str, char quote, t_env *env_lst);
t_values	*lx_collect_env(t_lexer *lexer, t_env *env_lst);
void		free_token(t_token **cmd);
void		free_token_ws(t_token **cmd);
void		collect_process(char **str, char **value, t_lexer *lexer);
char		*replace_char(char *str, char ori, char rep);
void		*ft_realloc(void *ptr, size_t size);
int			find_char_index(char *str, char c);
char		*remove_char(char *str, char charToRemmove);
int			count_words(char *str);
void		d_node(t_token **head, t_token *prev);
t_lexer		*init_lx(char *str);
void		lx_advance(t_lexer *lexer);
void		lx_skip_ws(t_lexer *lexer);
char		*lx_getchar_as_str(t_lexer *lexer);
t_values	*lx_collect_str(t_lexer *lexer);
void		rep_handle(int *count, char *str, int i);
int			handle_rep_pipe(char *str, int *i);
int			validate_rep_pipe(char *str);
int			handle_repitition(char *str, int *i);
int			validate_rep_redir(char *str, char redir);
t_token		*get_list_no_ws(t_token *cmd);
t_token		*return_list_token(char *line, t_env *env_list);
t_token		*get_list_no_ws(t_token *cmd);
void		store_name_node(t_token **tok, t_name **prev,
				t_name **lst, int mode);
char		*allocate(char *value, char *str);
t_cmd		*allocate_cmd(t_token *tok);
t_values	*lx_collect_quote(t_lexer *lexer, char quote, t_env *env_lst);
void		ignore_inside_quotes(char str, int *value, int *flag);
void		ignore_quotes(char *str, int *i, char quote, int *flag);
int			validate_pipes(char *str);
int			validate_line(char *str);
int			check_line_correctness(char *str);
int			validate_repetition(char *str, char redir1, char redir2);
int			validate_redirs(char *str);
int			validate_quote_type(char *str, char quote1, char quote2);
int			validate_quotes(char *str);
int			is_op(char c);
t_values	*lx_handle_operations(t_lexer *lexer);
t_values	*lx_collect_redirs(t_lexer *lexer, char redir);
t_values	*init_values(int type, char *value, char quote);
t_values	*lx_advance_wtok(t_lexer *lexer, t_values *token);
t_values	*lx_collect_spaces(t_lexer *lexer);
t_values	*lx_get_next_tok(t_lexer *lexer, t_env *env_lst);
t_token		*init_tok(t_values *values);
t_token		*create_lst_token(t_lexer *lexer, t_env *env_lst);
char		*append_quotes(char *value, char *str);
void		manage_tokens(t_token **cmd_old);
t_cmd		*fill_cmd(t_token *tok, t_cmd *cmd);
t_cmd		*fill_cmd_args(t_token *tok, t_cmd *cmd);
char		*expand_key(char *env_var, t_env *lst);
char		**copy_envp(char **envp);
t_env		*env_to_list(char **envp);
char		*ft_strcat(char *dest, char *src);
t_token		*handle_flaggin_files(t_token *tok);
t_cmd		*fill_args_list(t_cmd *cmd);
t_cmd		*fill_cmd_files(t_token *tok, t_cmd *cmd);
void		free_data(t_data *data);
void		free_cmd_lst(t_cmd *cmds);
void		free_name_lst(t_name *lst);
void		properly_ignore(char *str, int *i, int *flag);
int			get_size_envp(char **str);
t_token		*init_files_values(t_token *tok);
t_token		*flag_output_files(t_token *tok);
t_token		*flag_input_files(t_token *tok);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strstr(char *str, char *to_find);
char		*ft_readlinee(char *prompt);
int			ft_freee(void *ptr, int ret);
void		*ft_malloc(size_t count, size_t size, int is_exit);
void		remove_quotes(char *value);
void		remove_quotess(char *value);
void		check_n_expandd(char *value, char *new, int *i, int *j);
int			get_expansion_len(char *var, int *i);
char		*get_value_from_env(char *value, int *i);
int			check_malloc(void *to_be_checked, void *to_be_freed, int is_exit);
t_cmd		*fill_cmd_hdocs(t_token *tok, t_cmd *cmd);
int			read_heredocs(void);
char		*ft_strndup(const char *s1, size_t size);
int			check_if_input(char *str);
int			size_cmd(t_token *tok);
t_name		*fill_lst_files(t_name *lst, t_token **token);
void		file_collection(t_token *tok, t_name **prev, t_name **lst);
void		def_file_end(t_name **prev, t_name **lst);
t_cmd		*fill_input_source(t_cmd *cmds);

// errors
# define QUOTES "syntax error: unclosed quotes"
# define UNXPCT "syntax error near unexpected token \'"

#endif
