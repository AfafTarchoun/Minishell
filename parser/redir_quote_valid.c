/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_quote_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:51:54 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/29 01:02:21 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

void	ignore_quotes(char *str, int *i, char quote, int *flag)
{
	if (str[*i] == quote)
	{
		(*i)++;
		while (str[*i] != quote && str[*i])
			(*i)++;
		(*i)++;
		*flag = 1;
	}
}

int	validate_pipes(char *str)
{
	int	i;
	int	count_flag[2];

	i = 0;
	count_flag[0] = 0;
	count_flag[1] = 0;
	if (str[0] == '|')
		return (0);
	while (str[i])
	{
		properly_ignore(str, &i, &count_flag[1]);
		if (str[i] == '|')
			count_flag[0]++;
		if (str[i] == '|' && str[i + 1] == '\0')
			return (0);
		if (str[i] == '|' && str[i + 1] == '|')
			return (0);
		else
			count_flag[0] = 0;
		if (count_flag[0] > 1)
			return (0);
		i++;
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

int	check_line_correctness(char *str)
{
	if (str[0] == '\0')
		return (0);
	if (!validate_pipes(str))
	{
		printf("WARNING : |PIPE| Invalid\n");
		return (0);
	}
	else if (!validate_redirs(str))
	{
		printf("WARNING : <REDIRS> Invalid\n");
		return (0);
	}
	else if (!validate_quotes(str))
	{
		printf("WARNING : \"'QUOTES'\" Invalid\n");
		return (0);
	}
	else if (!validate_line(str))
	{
		printf("WARNING : syntax error\n");
		return (0);
	}
	return (1);
}
