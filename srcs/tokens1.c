/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:48:13 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 22:09:39 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

t_token	*init_tok(t_values *values)
{
	t_token	*tok;

	tok = (t_token *)malloc(sizeof(t_token));
	tok->value = values->value;
	tok->type = values->type;
	tok->quote = values->quote;
	return (tok);
}

t_token	*create_lst_token(t_lexer *lexer, t_env *env_lst)
{
	t_values	*tok;
	t_token		*cmd;
	t_token		*head;

	head = NULL;
	tok = lx_get_next_tok(lexer, env_lst);
	if (tok != NULL)
	{
		cmd = init_tok(tok);
		free(tok);
		head = cmd;
	}
	while (tok)
	{
		tok = lx_get_next_tok(lexer, env_lst);
		if (tok != NULL)
		{
			cmd->next = init_tok(tok);
			free(tok);
			cmd = cmd->next;
		}
		else
			cmd->next = NULL;
	}
	return (head);
}

void	manage_tokens(t_token **cmd_old)
{
	t_token	*cmd;
	t_token	*prev;

	cmd = *cmd_old;
	prev = NULL;
	while (cmd)
	{
		if (prev && prev->quote != ' ' && cmd->quote != ' '
			&& prev->type == OTHER && cmd->type == OTHER)
		{
			prev->value = append_quotes(prev->value, cmd->value);
			d_node(&cmd, prev);
			cmd = prev;
		}
		else
			prev = cmd;
		prev = cmd;
		if (cmd)
			cmd = cmd->next;
	}
}
