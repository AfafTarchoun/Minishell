/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:07:18 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/28 21:18:55 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

char	*allocate(char *value, char *str)
{
	value = ft_realloc(value, ft_strlen(value)
			+ ft_strlen(str) + 1 * sizeof(char));
	return (value);
}

char	*append_quotes(char *value, char *str)
{
	value = allocate(value, str);
	ft_strcat(value, str);
	return (value);
}

t_token	*lx_collect_quote(t_lexer *lexer, char quote, t_exec *exec)
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
		collect_process(&str, &value, lexer);
	if (lexer->c == quote)
		lx_advance(lexer);
	value = remove_char(value, quote);
	if (find_char_index(value, '$') != -2)
		value = expand_env(value, quote, exec);
	return (init_token(WORD, value, quote));
}
