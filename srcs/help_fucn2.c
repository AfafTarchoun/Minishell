/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_fucn2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:13:52 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 22:09:40 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	ft_perror(char *name, char *error, int freeable)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	if (!error)
	{
		perror(NULL);
		return (-1);
	}
	ft_putendl_fd(error, 2);
	if (freeable)
		free(error);
	return (-1);
}

void	collect_process(char **str, char **value, t_lexer *lexer)
{
	char	*tmp;

	tmp = *value;
	*str = lx_getchar_as_str(lexer);
	if (**value == 0)
		*value = ft_strdup(*str);
	else
		*value = ft_strjoin(tmp, *str);
	free(tmp);
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

int	get_size_envp(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*append_quotes(char *value, char *str)
{
	value = allocate(value, str);
	ft_strcat(value, str);
	return (value);
}
