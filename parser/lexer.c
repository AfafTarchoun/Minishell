/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:00:53 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/22 10:10:45 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

t_lexer	*init_lx(char *str)
{
	t_lexer	*lexer;

	lexer = (t_lexer *)malloc(sizeof(t_lexer));
	lexer->str = str;
	lexer->i = 0;
	lexer->c = str[lexer->i];
	return (lexer);
}

void	lx_advance(t_lexer *lexer)
{
	if (lexer->c && lexer->i < ft_strlen(lexer->str))
	{
		lexer->i++;
		lexer->c = lexer->str[lexer->i];
	}
}

void	lx_skip_ws(t_lexer *lexer)
{
	while (lexer->c == ' ' || lexer->c == 10 || lexer->c == '\\')
		lx_advance(lexer);
}

char	*lx_getchar_as_str(t_lexer *lexer)
{
	char	*str;

	str = (char *)malloc(sizeof(char) + 1);
	str[0] = lexer->c;
	str[1] = '\0';
	return (str);
}

t_token	*lx_collect_str(t_lexer *lexer)
{
	char	*value;
	char	*str;

	value = (char *)malloc(sizeof(char) + 1);
	value[0] = '\0';
	while (ft_isalnum(lexer->c))
	{
		str = lx_getchar_as_str(lexer);
		value = ft_realloc(value, ft_strlen(value)
				+ ft_strlen(str) + 1 * sizeof(char));
		ft_strcat(value, str);
		lx_advance(lexer);
	}
	return (init_token(WORD, value, 0));
}
