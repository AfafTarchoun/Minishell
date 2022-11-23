/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:21:43 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 23:24:09 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

t_name	*fill_lst_files(t_name *lst, t_token **token)
{
	int		i;
	t_token	*tok;
	t_name	*head;
	t_name	*prev;

	i = 0;
	tok = *token;
	head = NULL;
	while (tok && (ft_strcmp(tok->value, "|") != 0))
	{
		if (tok->file != 0 && tok->file != 3 && !is_op(tok->value[0]))
		{
			if (lst == NULL)
			lst = (t_name *)malloc(sizeof(t_name));
			i++;
			if (i == 1)
				head = lst;
			file_collection(tok, &prev, &lst);
		}
		tok = tok->next;
	}
	def_file_end(&prev, &lst);
	*token = tok;
	return (head);
}

t_cmd	*fill_cmd_files(t_token *tok, t_cmd *cmd)
{
	t_cmd	*head;
	int		flag;

	head = cmd;
	while (tok)
	{
		flag = 0;
		cmd->files = NULL;
		cmd->files = fill_lst_files(cmd->files, &tok);
		cmd = cmd->next;
		if (tok)
			tok = tok->next;
	}
	return (head);
}

t_name	*fill_lst_hdocs(t_name *lst, t_token **token)
{
	int		i;
	t_token	*tok;
	t_name	*head;
	t_name	*prev;

	i = 0;
	tok = *token;
	head = NULL;
	while (tok && (ft_strcmp(tok->value, "|") != 0))
	{
		if (tok->file == 3 && !is_op(tok->value[0]))
		{
			if (lst == NULL)
				lst = (t_name *)malloc(sizeof(t_name));
			i++;
			if (i == 1)
				head = lst;
			file_collection(tok, &prev, &lst);
		}
		tok = tok->next;
	}
	def_file_end(&prev, &lst);
	*token = tok;
	return (head);
}

t_cmd	*fill_cmd_hdocs(t_token *tok, t_cmd *cmd)
{
	t_cmd	*head;
	int		flag;

	head = cmd;
	while (tok)
	{
		flag = 0;
		cmd->heredoc_lst = NULL;
		cmd->heredoc_lst = fill_lst_hdocs(cmd->heredoc_lst, &tok);
		cmd = cmd->next;
		if (tok)
			tok = tok->next;
	}
	return (head);
}
