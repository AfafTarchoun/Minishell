/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:16:29 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/27 00:48:11 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

void	rep_handle(int *count, char *str, int i)
{
	if (str[i] == '\"' || str[i] == '\'')
		(*count)++;
	if (*count == 2)
		*count = 0;
}

void	ignore_quotes(char *str, int *i, char quote, int *flag)
{
	if (str[*i] == quote)
	{
		(*i)++;
		while (str[*i] != quote)
			(*i)++;
		(*i)++;
		*flag = 1;
	}
}

int	handle_rep_pipe(char *str, int *i)
{
	int	flag;
	
	flag = 0;
	while (str[*i] == ' ')
		(*i)++;
	ignore_quotes(str, i, '\"', &flag);
	ignore_quotes(str, i, '\'', &flag);
	if (flag == 1)
		return (1);
	if (!ft_isalnum(str[*i]) && str[*i] != '>' && str[*i] != '<')
		return (0);
	return (1);
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
			if (handle_rep_pipe(str, &i) == 0)
				return (0);
		}
		}
		i++;
		if (i > ft_strlen(str))
		i = ft_strlen(str);
	}
	return (1);
}

int	handle_repitition(char *str, int *i)
{
	int	flag;
	
	flag = 0;
	while (str[*i] == ' ')
		(*i)++;
	ignore_quotes(str, i, '\"', &flag);
	ignore_quotes(str, i, '\'', &flag);
	if (flag == 1)
		return (1);
	if (!ft_isalnum(str[*i]))
		return (0);
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
