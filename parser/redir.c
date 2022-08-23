/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:05:38 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/23 22:33:50 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

int	is_op(char c)
{
	if (c == '>' || c == '<' || c == '|')
		return (1);
	return (0);
}

t_token	*lx_handle_operations(t_lexer *lexer)
{
	t_token	*tok;

	if (lexer->c == '>' || lexer->c == '<')
		return (lx_collect_redirs(lexer, lexer->c));
	if (lexer->c == '|')
	{
		tok = init_token(PIPE, lx_getchar_as_str(lexer), 0);
		return (lx_advance_wtok(lexer, tok));
	}
	return (NULL);
}

t_token	*lx_collect_redirs(t_lexer *lexer, char redir)
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
		str = lx_getchar_as_str(lexer);
		value = ft_realloc(value, ft_strlen(value)
				+ ft_strlen(str) + 1 * sizeof(char));
		ft_strcat(value, str);
		free(str);
		lx_advance(lexer);
	}
	if (count == 1 && redir == '>')
		return (init_token(REDIRIN, value, 0));
	else if (count == 2 && redir == '>')
		return (init_token(APPEND, value, 0));
	else if (count == 1 && redir == '<')
		return (init_token(REDIROUT, value, 0));
	else if (count == 2 && redir == '<')
		return (init_token(HEREDOC, value, 0));
	return (NULL);
}
