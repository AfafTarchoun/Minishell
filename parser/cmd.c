/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:08:08 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/21 21:46:31 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

t_cmd	*init_cmd(t_token *tok)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->tok = tok;
	return (cmd);
}

t_cmd	*create_lst_cmd(t_lexer *lexer)
{
	t_token	*tok;
	t_cmd	*cmd;
	t_cmd	*head;

	tok = lx_get_next_tok(lexer);
	if (tok != NULL)
	{
		cmd = init_cmd(tok);
		head = cmd;
	}
	while (tok)
	{
		tok = lx_get_next_tok(lexer);
		if (tok != NULL)
		{
			cmd->next = init_cmd(tok);
			cmd = cmd->next;
		}
		else
			cmd->next = NULL;
	}
	return (head);
}