/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:22:08 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/05 17:47:48 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

t_values	*init_values(int type, char *value, char quote)
{
	t_values	*tok;

	tok = (t_values *)malloc(sizeof(t_values));
	tok->type = type;
	tok->value = value;
	tok->quote = quote;
	return (tok);
}

t_values	*lx_advance_wtok(t_lexer *lexer, t_values *token)
{
	lx_advance(lexer);
	return (token);
}

int	ft_isspace(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

t_values	*lx_collect_spaces(t_lexer *lexer)
{
	char	*value;

	value = (char *)malloc(sizeof(char) * 2);
	value[0] = ' ';
	value[1] = '\0';
	while (ft_isspace(lexer->c))
		lx_advance(lexer);
	return (init_values(WSPACE, value, ' '));
}

t_values	*lx_get_next_tok(t_lexer *lexer, t_env *env_lst)
{
	while (lexer->c && lexer->i < ft_strlen(lexer->str))
	{
		if (lexer->c == ' ')
			return (lx_collect_spaces(lexer));
		if (lexer->c == '\"' || lexer->c == '\'')
			return (lx_collect_quote(lexer, lexer->c, env_lst));
		if (lexer->c == '$')
			return (lx_collect_env(lexer, env_lst));
		if (lexer->c != ' ' && !is_op(lexer->c))
			return (lx_collect_str(lexer));
		if (is_op(lexer->c))
			return (lx_handle_operations(lexer));
	}
	return (NULL);
}
