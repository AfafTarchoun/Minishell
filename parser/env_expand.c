/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:09:23 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/21 21:39:10 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

char *expand_env(char *str, char quote)
{
	char *tmp;
	
	if (quote != '\'')
	{
		tmp = str;
		str = strdup("/EXPAND/");
		free(tmp);
	}
	return (str);
}

t_token	*lx_collect_env(t_lexer *lexer)
{
	char	*value;
	char	*str;

	value = (char *)malloc(sizeof(char) + 1);
	value[0] = '\0';
	while (isalnum(lexer->c)  || lexer->c == '$')
	{
		str = lx_getchar_as_str(lexer);
		value = ft_realloc(value, strlen(value) + strlen(str) + 1 * sizeof(char));
		strcat(value, str);
		lx_advance(lexer);
	}
	if (find_char_index(value, '$') != -2)
		value = expand_env(value, 0);
	return (init_token(WORD, value, 0));
}