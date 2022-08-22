/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:04:01 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/22 11:27:43 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

t_token	*init_token(int type, char *value, char quote)
{
	t_token	*tok;

	tok = (t_token *)malloc(sizeof(t_token));
	tok->type = type;
	tok->value = value;
	tok->quote = quote;
	return (tok);
}

t_token	*lx_collect_spaces(t_lexer *lexer)
{
	char	*value;

	value = (char *)malloc(sizeof(char) + 2);
	value[0] = ' ';
	value[1] = '\0';
	while (ft_isspace(lexer->c))
		lx_advance(lexer);
	return (init_token(SPACE, value, ' '));
}

t_token	*lx_advance_wtok(t_lexer *lexer, t_token *token)
{
	lx_advance(lexer);
	return (token);
}

t_token	*lx_get_next_tok(t_lexer *lexer, t_exec *exec)
{
	t_token	*tok;

	while (lexer->c && lexer->i < ft_strlen(lexer->str))
	{
		if (lexer->c == ' ' || lexer->c == 10)
			return (lx_collect_spaces(lexer));
		if (ft_isalnum(lexer->c))
			return (lx_collect_str(lexer));
		if (lexer->c == '$')
			return (lx_collect_env(lexer, exec));
		if (lexer->c == '\"' || lexer->c == '\'')
			return (lx_collect_quote(lexer, lexer->c, exec));
		if (lexer->c == '>' || lexer->c == '<')
			return (lx_collect_redirs(lexer, lexer->c));
		if (lexer->c == '|')
		{
			tok = init_token(PIPE, lx_getchar_as_str(lexer), 0);
			return (lx_advance_wtok(lexer, tok));
		}
		if (lexer->c == '=')
		{
			tok = init_token(EQUALS, lx_getchar_as_str(lexer), 0);
			return (lx_advance_wtok(lexer, tok));
		}
	}
	return (NULL);
}
