/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fucn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:14:36 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 23:24:56 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	free_name_lst(t_name *lst)
{
	t_name	*tmp;

	while (lst)
	{
		tmp = lst;
		free(lst->name);
		lst = lst->next;
		free(tmp);
	}
}

void	free_cmd_files(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->files)
			free_name_lst(cmd->files);
		cmd = cmd->next;
	}
}

void	free_cmd_hdocs(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->heredoc_lst)
			free_name_lst(cmd->heredoc_lst);
		cmd = cmd->next;
	}
}

void	unlink_files(t_cmd *cmds)
{
	if (cmds->heredoc_path)
		unlink(cmds->heredoc_path);
	free(cmds->heredoc_path);
	if (cmds->heredoc > 0)
		close(cmds->heredoc);
	if (cmds->out_file > 0)
		close(cmds->out_file);
	if (cmds->in_file)
		close(cmds->in_file);
}

void	free_cmd_lst(t_cmd *cmds)
{
	t_cmd	*tmp;
	int		i;

	free_cmd_files(cmds);
	free_cmd_hdocs(cmds);
	while (cmds)
	{
		i = 0;
		while (cmds->args[i])
		{
			free(cmds->args[i]);
			i++;
		}
		free(cmds->args);
		free(cmds->cmd);
		tmp = cmds;
		unlink_files(cmds);
		cmds = cmds->next;
		free(tmp);
	}
		g_data.cmds = NULL;
}
