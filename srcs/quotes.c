/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:26:13 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 22:09:38 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	*allocate(char *value, char *str)
{
	value = ft_realloc(value, ft_strlen(value)
			+ ft_strlen(str) + 1 * sizeof(char));
	return (value);
}

t_values	*lx_collect_quote(t_lexer *lexer, char quote, t_env *env_lst)
{
	char	*value;
	char	*str;

	lx_advance(lexer);
	value = (char *)malloc(sizeof(char));
	value[0] = '\0';
	if (lexer->c == quote)
	{
		lx_advance(lexer);
		return (init_values(OTHER, value, quote));
	}
	while (lexer->c != quote)
		collect_process(&str, &value, lexer);
	if (lexer->c == quote)
		lx_advance(lexer);
	value = remove_char(value, quote);
	if (find_char_index(value, '$') != -2)
		value = expand_env(value, quote, env_lst);
	return (init_values(OTHER, value, quote));
}
