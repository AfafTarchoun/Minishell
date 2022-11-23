/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_quote_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:51:54 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 22:09:39 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	ignore_inside_quotes(char str, int *value, int *flag)
{
	if (str == '\'' || str == '\"')
	{
		*value = 0;
		(*flag)++;
	}
	if (*flag == 2)
	{
		*flag = 0;
		*value = 1;
	}
}

void	ignore_quotes(char *str, int *i, char quote, int *flag)
{
	if (str[*i] == quote)
	{
		(*i)++;
		while (str[*i] != quote)
			(*i)++;
		if (str[*i] == quote)
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
		if (str[i])
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
	if (!validate_quotes(str))
	{
		g_data.exit_code = 258;
		return (ft_perror("minishell", QUOTES, 0));
	}
	else if (!validate_pipes(str))
	{
		g_data.exit_code = 258;
		return (ft_perror("minishell", UNXPCT, 0));
	}
	else if (!validate_redirs(str))
	{
		g_data.exit_code = 258;
		return (ft_perror("minishell", UNXPCT, 0));
	}
	else if (!validate_line(str))
	{
		g_data.exit_code = 258;
		return (ft_perror("minishell", UNXPCT, 0));
	}
	return (1);
}
