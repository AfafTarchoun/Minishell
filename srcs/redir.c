/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:27:22 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 22:09:39 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	is_op(char c)
{
	if (c == '>' || c == '<' || c == '|')
		return (1);
	return (0);
}

t_values	*lx_handle_operations(t_lexer *lexer)
{
	t_values	*tok;

	if (lexer->c == '>' || lexer->c == '<')
		return (lx_collect_redirs(lexer, lexer->c));
	if (lexer->c == '|')
	{
		tok = init_values(PIPE, lx_getchar_as_str(lexer), 0);
		return (lx_advance_wtok(lexer, tok));
	}
	return (NULL);
}

t_values	*lx_collect_redirs(t_lexer *lexer, char redir)
{
	char	*value;
	char	*str;
	int		count;

	count = 0;
	value = (char *)malloc(sizeof(char) + 1);
	value[0] = '\0';
	while (lexer->c == redir)
	{
		count++;
		collect_process(&str, &value, lexer);
	}
	if (count == 1 && redir == '>')
		return (init_values(INF, value, 0));
	else if (count == 2 && redir == '>')
		return (init_values(APPF, value, 0));
	else if (count == 1 && redir == '<')
		return (init_values(OUTF, value, 0));
	else if (count == 2 && redir == '<')
		return (init_values(HRDOC, value, 0));
	return (NULL);
}
