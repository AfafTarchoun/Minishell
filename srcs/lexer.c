/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:24:26 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 22:09:39 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

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
	while (lexer->c == ' ' || lexer->c == 10)
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

t_values	*lx_collect_str(t_lexer *lexer)
{
	char	*value;
	char	*str;

	value = (char *)malloc(sizeof(char) + 1);
	value[0] = '\0';
	while (lexer->c != ' ' && !is_op(lexer->c)
		&& lexer->c != '\"' && lexer->c != '\''
		&& lexer->c != '$' && lexer->c)
		collect_process(&str, &value, lexer);
	return (init_values(OTHER, value, 0));
}
