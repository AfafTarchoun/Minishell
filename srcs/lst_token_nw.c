/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_token_nw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:37:22 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 22:09:38 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

t_token	*copy_token(t_token *token)
{
	t_token	*tok;

	tok = NULL;
	if (token)
	{
		tok = (t_token *)malloc(sizeof(t_token));
		tok->type = token->type;
		tok->value = ft_strdup(token->value);
		tok->quote = token->quote;
	}
	return (tok);
}

void	get_no_ws_head(t_token **tok, t_token **lst, t_token **head)
{
	if ((*tok)->quote != ' ')
		*lst = copy_token(*tok);
	else
	{
		*tok = (*tok)->next;
		*lst = copy_token(*tok);
	}
	*head = *lst;
}

t_token	*get_list_no_ws(t_token *tok)
{
	t_token	*lst;
	t_token	*head;

	lst = NULL;
	head = NULL;
	get_no_ws_head(&tok, &lst, &head);
	if (!tok)
		return (NULL);
	else
		tok = tok->next;
	while (tok)
	{
		if (tok->quote != ' ')
		{
			lst->next = copy_token(tok);
			lst = lst->next;
		}
		tok = tok->next;
	}
	lst->next = NULL;
	return (head);
}

t_token	*return_list_token(char *line, t_env *env_list)
{
	t_lexer	*lexer;
	t_token	*cmd;
	t_token	*head;

	lexer = init_lx(line);
	cmd = create_lst_token(lexer, env_list);
	free(lexer->str);
	free(lexer);
	head = cmd;
	manage_tokens(&cmd);
	return (head);
}
