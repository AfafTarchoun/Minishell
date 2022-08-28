/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 02:33:31 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/28 02:34:17 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

t_token	*lx_collect_env(t_lexer *lexer, t_exec *exec)
{
	char	*value;
	char	*str;
	char	*tmp;

	value = (char *)malloc(sizeof(char) + 1);
	value[0] = '\0';
	collect_process(&str, &value, lexer);
	while (lexer->c == '_')
		collect_process(&str, &value, lexer);
	while (ft_isalnum(lexer->c))
		collect_process(&str, &value, lexer);
	if (find_char_index(value, '$') != -2)
	{
		if (ft_isdigit(value[1]))
		{
			tmp = value;
			value = handle_num_env(value);
			free(tmp);
		}
		else
			value = expand_env_word(value, 0, exec);
	}
	return (init_token(WORD, value, 0));
}
