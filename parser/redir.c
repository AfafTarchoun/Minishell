/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:05:38 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/21 21:39:20 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

t_token	*lx_collect_redirs(t_lexer *lexer, char redir)
{
	char	*value;
	char	*str;
	int		count;

	count = 0;
	value = (char *)malloc(sizeof(char) + 1);
	value[0] = '\0';
	while (lexer->c == redir)
	{
		count++;
		str = lx_getchar_as_str(lexer);
		value = ft_realloc(value, strlen(value) + strlen(str) + 1 * sizeof(char));
		strcat(value, str);
		lx_advance(lexer);
	}
	if (count == 1 && redir == '>')
		return (init_token(REDIRIN, value, 0));
	else if (count == 2 && redir == '>')
		return (init_token(APPEND, value, 0));
	else if (count == 1 && redir == '<')
		return (init_token(REDIROUT, value, 0));
	else if (count == 2 && redir == '<')
		return (init_token(HEREDOC, value, 0));
	return (NULL);
}