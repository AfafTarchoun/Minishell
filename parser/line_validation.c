/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:16:29 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/26 21:20:00 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

int	handle_repitition(char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
	if (!isalnum(str[*i]))
		return (0);
	else if (!isalnum(str[*i]))
		return (0);
	return (1);
}

void	rep_handle(int *count, char *str, int i)
{
	if (str[i] == '\"' || str[i] == '\'')
		(*count)++;
	if (*count == 2)
		*count = 0;
}

int	validate_rep_pipe(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		rep_handle(&count, str, i);
		if (count == 0)
		{
			if (str[i] == '|')
			{
				i++;
				if (handle_repitition(str, &i) == 0)
					return (0);
			}
		}
		i++;
	}
	return (1);
}

int	validate_rep_redir(char *str, char redir)
{
	int	i[2];

	i[0] = 0;
	i[1] = 0;
	while (str[i[0]])
	{
		rep_handle(&i[1], str, i[0]);
		if (i[1] == 0)
		{
			if (str[i[0]] == redir && str[i[0] + 1] != redir)
			{
				i[0]++;
				if (handle_repitition(str, &i[0]) == 0)
					return (0);
			}
			else if (str[i[0]] == redir && str[i[0] + 1] == redir)
			{
				i[0] = i[0] + 2;
				if (handle_repitition(str, &i[0]) == 0)
					return (0);
			}
		}
		i[0]++;
	}
	return (1);
}

int	validate_line(char *str)
{
	if (!validate_rep_pipe(str))
		return (0);
	if (!validate_rep_redir(str, '>'))
		return (0);
	if (!validate_rep_redir(str, '<'))
		return (0);
	return (1);
}
