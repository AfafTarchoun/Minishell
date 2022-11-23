/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:33:01 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 23:19:05 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

t_cmd	*init_allocate_cmd(t_cmd **head, t_token **tok, int *flag)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->cmd = NULL;
	(*tok) = (*tok)->next;
	*head = NULL;
	*flag = 0;
	return (cmd);
}

t_cmd	*allocate_cmd(t_token *tok)
{
	t_cmd	*cmd;
	t_cmd	*head;
	int		flag;

	cmd = init_allocate_cmd(&head, &tok, &flag);
	while (tok)
	{
		if (ft_strcmp(tok->value, "|") == 0)
		{
			flag++;
			if (flag == 1)
				head = cmd;
			cmd->next = (t_cmd *)malloc(sizeof(t_cmd));
			cmd = cmd->next;
			cmd->cmd = NULL;
			tok = tok->next;
		}
		if (tok)
			tok = tok->next;
	}
	cmd->next = NULL;
	if (!head)
		head = cmd;
	return (head);
}

void	fill_cmd_data(t_cmd *cmd)
{
	cmd->heredoc_lst = NULL;
	cmd->heredoc_path = NULL;
	cmd->heredoc = -1;
	cmd->out_file = -1;
	cmd->in_file = -1;
}

t_cmd	*fill_cmd(t_token *tok, t_cmd *cmd)
{
	t_cmd	*head;

	if (!is_op(tok->value[0]))
		cmd->cmd = ft_strdup(tok->value);
	else
		cmd->cmd = ft_strdup("");
	head = cmd;
	fill_cmd_data(cmd);
	tok = tok->next;
	while (tok)
	{
		if (ft_strcmp(tok->value, "|") == 0)
		{
			cmd = cmd->next;
			fill_cmd_data(cmd);
			tok = tok->next;
			if (!is_op(tok->value[0]))
				cmd->cmd = ft_strdup(tok->value);
			else
				cmd->cmd = ft_strdup("");
		}
		if (tok)
			tok = tok->next;
	}
	return (head);
}

int	size_cmd(t_token *tok)
{
	int	i;

	i = 0;
	while (tok && (ft_strcmp(tok->value, "|") != 0))
	{
		if (tok->file == 0)
			i++;
		tok = tok->next;
	}
	return (i);
}
