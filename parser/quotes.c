/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:07:18 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/21 21:39:17 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

t_token	*lx_collect_quote(t_lexer *lexer, char quote)
{
	char	*value;
	char	*str;

	lx_advance(lexer);
	value = (char *)malloc(sizeof(char) + 1);
	value[0] = '\0';
	while (lexer->c == quote)
		lx_advance(lexer);
	while (lexer->c != quote)
	{
		str = lx_getchar_as_str(lexer);
		value = ft_realloc(value, strlen(value) + strlen(str) + 1 * sizeof(char));
		strcat(value, str);
		lx_advance(lexer);
	}
	while (lexer->c == quote)
		lx_advance(lexer);
	value = remove_char(value, quote);
	if (find_char_index(value, '$') != -2)
		value = expand_env(value, quote);
	return (init_token(WORD, value, quote));
}