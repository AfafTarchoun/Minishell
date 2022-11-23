/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:18:41 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 23:19:09 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	**init_cmd_args_vars(int *flag, int *size, int *i, t_token *tok)
{
	char	**args;

	*flag = 0;
	*size = size_cmd(tok) + 1;
	args = (char **)malloc(sizeof(char *) * *size);
	*i = 0;
	return (args);
}

void	fill_args_array(t_token **tok, t_cmd **cmd, int *i, int *flag)
{
	while (*tok && ft_strcmp((*tok)->value, "|") != 0)
	{
		if ((*tok)->file == 0)
		{
			(*cmd)->args[*i] = ft_strdup((*tok)->value);
			(*i)++;
			*flag = 1;
		}
		*tok = (*tok)->next;
	}
}

t_cmd	*fill_cmd_args(t_token *tok, t_cmd *cmd)
{
	t_cmd	*head;
	int		size;
	int		i;
	int		flag;

	head = cmd;
	while (tok)
	{
		cmd->args = init_cmd_args_vars(&flag, &size, &i, tok);
		fill_args_array(&tok, &cmd, &i, &flag);
		if ((!tok || ft_strcmp(tok->value, "|") == 0) && flag == 0)
			cmd->args[i] = NULL;
		if (flag == 1)
		{
			cmd->args[i] = NULL;
			cmd = cmd->next;
		}
		if (tok)
			tok = tok->next;
	}
	return (head);
}
