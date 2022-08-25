/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_quote_valid1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:52:57 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/25 20:19:44 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

int	validate_repetition(char *str, char redir1, char redir2)
{
	int	i;
	int	count;
	int	flag;
	int	value;

	i = 0;
	count = 0;
	value = 1;
	flag = 0;
	while (str[i])
	{
		ignore_inside_quotes(str[i], &value, &flag);
		if (str[i] == redir1 && flag == 0)
		{
			if (str[i + 1] == redir2)
				return (0);
			count = count + value;
		}
		else
			count = 0;
		if (count > 2)
			return (0);
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
