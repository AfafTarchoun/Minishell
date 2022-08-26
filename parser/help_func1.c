/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:21:06 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/26 21:17:12 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

void	collect_process(char **str, char **value, t_lexer *lexer)
{
	*str = lx_getchar_as_str(lexer);
	*value = allocate(*value, *str);
	ft_strcat(*value, *str);
	free(*str);
	lx_advance(lexer);
}

char	*replace_char(char *str, char ori, char rep)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ori)
			str[i] = rep;
		i++;
	}
	return (str);
}
