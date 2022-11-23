/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:49:22 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/05 17:20:14 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

t_cmd	*get_cmd_data(t_token *tok)
{
	t_cmd	*cmds;

	if (!tok)
		return (NULL);
	cmds = allocate_cmd(tok);
	cmds = fill_cmd(tok, cmds);
	cmds = fill_cmd_args(tok, cmds);
	cmds = fill_cmd_files(tok, cmds);
	cmds = fill_cmd_hdocs(tok, cmds);
	cmds = fill_input_source(cmds);
	return (cmds);
}

t_env	*change_old_pwd(t_env *lst)
{
	t_env	*head;
	char	*tmp;

	head = lst;
	tmp = NULL;
	while (lst)
	{
		if (ft_strcmp(lst->var, "OLDPWD") == 0)
		{
			tmp = lst->value;
			lst->value = ft_strdup("");
			free(tmp);
			break ;
		}
		lst = lst->next;
	}
	return (head);
}

void	init_data(char **envp)
{
	g_data.env = copy_envp(envp);
	g_data.env_lst = env_to_list(g_data.env);
	g_data.env_lst = change_old_pwd(g_data.env_lst);
	g_data.exit_code = 0;
}

void	exec(char *line)
{
	g_data.tok = return_list_token(line, g_data.env_lst);
	if (g_data.tok)
	{			
		g_data.no_ws = get_list_no_ws(g_data.tok);
		g_data.no_ws = handle_flaggin_files(g_data.no_ws);
		g_data.cmds = get_cmd_data(g_data.no_ws);
		if (g_data.cmds)
		{
			read_heredocs();
			ft_execute(g_data.cmds);
		}
	}
	free_cmd_lst(g_data.cmds);
	free_token(&(g_data.tok));
	free_token_ws(&(g_data.no_ws));
}

int	main(int ac, char **av, char **envp)
{
	char	*line;

	(void) ac;
	(void) av;
	if (!envp)
		return (0);
	g_data.loc = PROMPT;
	signal(SIGINT, sig_int_handler);
	signal(SIGQUIT, sig_quit_handler);
	line = readline("MINISHELL$> ");
	init_data(envp);
	while (line)
	{
		g_data.sig_caught = 0;
		if (*line)
			add_history(line);
		if (check_line_correctness(line) != -1)
			exec(line);
		else
			free(line);
		g_data.loc = PROMPT;
		line = readline("MINISHELL$> ");
	}
	ft_putendl_fd("exit", 2);
	return (0);
}
