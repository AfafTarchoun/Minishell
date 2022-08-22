/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:07:18 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/22 10:10:38 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

char	*append_quotes(char *value, char *str)
{
	value = ft_realloc(value, ft_strlen(value)
			+ ft_strlen(str) + 1 * sizeof(char));
	ft_strcat(value, str);
	return (value);
}

void	fix_quotes(t_cmd **cmd_old)
{
	t_cmd	*cmd;
	t_cmd	*prev;

	cmd = *cmd_old;
	prev = NULL;
	while (cmd)
	{
		//fix redir
		if (prev && prev->tok->quote != ' ' & cmd->tok->quote != ' ')
		{
			prev->tok->value = append_quotes(prev->tok->value, cmd->tok->value);
			delete_node(&cmd, prev);
			cmd = prev;
		}
		else
			prev = cmd;
			prev = cmd;
		if (cmd)
			cmd = cmd->next;
	}
}

t_token	*lx_collect_quote(t_lexer *lexer, char quote)
{
	char	*value;
	char	*str;

	lx_advance(lexer);
	value = (char *)malloc(sizeof(char) + 1);
	value[0] = '\0';
	if (lexer->c == quote)
	{
		lx_advance(lexer);
		return (init_token(WORD, value, quote));
	}
	while (lexer->c != quote)
	{
		str = lx_getchar_as_str(lexer);
		value = ft_realloc(value, ft_strlen(value)
				+ ft_strlen(str) + 1 * sizeof(char));
		ft_strcat(value, str);
		lx_advance(lexer);
	}
	if (lexer->c == quote)
		lx_advance(lexer);
	value = remove_char(value, quote);
	if (find_char_index(value, '$') != -2)
		value = expand_env(value, quote);
	return (init_token(WORD, value, quote));
}
