/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_quote_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:51:54 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/27 02:48:46 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

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
		(*i)++;
		*flag = 1;
	}
}

int validate_pipes(char *str)
{
  int i;
  int count;
  int flag;

  i = 0;
  count = 0;
  flag = 0;
  if (str[0] == '|')
    return (0);
  while (str[i])
  {
    ignore_quotes(str, &i, '\"', &flag);
    ignore_quotes(str, &i, '\'', &flag);
    if (str[i] == '|')
      count++;
    if (str[i] == '|' && str[i + 1] == '\0')
      return (0);
    if (str[i] == '|' && str[i + 1] == '|')
      return (0);
    else
      count = 0;
    if (count > 1)
      return (0);
    i++;
  }
  return(1);
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
