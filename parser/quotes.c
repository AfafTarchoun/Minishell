/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:07:18 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/23 22:30:47 by atarchou         ###   ########.fr       */
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
	{
		str = lx_getchar_as_str(lexer);
		value = ft_realloc(value, ft_strlen(value)
				+ ft_strlen(str) + 1 * sizeof(char));
		ft_strcat(value, str);
		free(str);
		lx_advance(lexer);
	}
	if (lexer->c == quote)
		lx_advance(lexer);
	value = remove_char(value, quote);
	if (find_char_index(value, '$') != -2)
		value = expand_env(value, quote, exec);
	return (init_token(WORD, value, quote));
}
