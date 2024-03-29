/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_quote_valid1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:52:57 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 22:09:39 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	properly_ignore(char *str, int *i, int *flag)
{
	while (str[*i] == '\"' || str[*i] == '\'')
	{
		ignore_quotes(str, i, '\"', flag);
		ignore_quotes(str, i, '\'', flag);
	}
}

int	validate_repetition(char *str, char redir1, char redir2)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (str[i])
	{
		properly_ignore(str, &i, &flag);
		if (str[i] == redir1)
		{
			if (str[i + 1] == redir2)
				return (0);
			count++;
		}
		else
			count = 0;
		if (count > 2)
			return (0);
		if (str[i])
			i++;
	}
	return (1);
}

int	validate_redirs(char *str)
{
	if (!validate_repetition(str, '>', '<'))
		return (0);
	else if (!validate_repetition(str, '<', '>'))
		return (0);
	return (1);
}

int	validate_quote_type(char *str, char quote1, char quote2)
{
	int	flag;
	int	iter[2];

	iter[0] = 0;
	iter[1] = 0;
	flag = 0;
	while (str[iter[0]])
	{
		if (str[iter[0]] == quote2 && iter[1] % 2 == 0)
			flag++;
		if (str[iter[0]] == quote1)
		{
			if (flag != 1)
				iter[1]++;
			if (flag == 2)
				flag = 0;
		}
		if (flag == 2)
			flag = 0;
		iter[0]++;
	}
	if (iter[1] % 2 == 0)
		return (1);
	else
		return (0);
}

int	validate_quotes(char *str)
{
	if (!validate_quote_type(str, '\"', '\''))
		return (0);
	else if (!validate_quote_type(str, '\'', '\"'))
		return (0);
	return (1);
}
