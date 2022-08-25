/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_quote_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:51:54 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/23 22:34:15 by atarchou         ###   ########.fr       */
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

int	validate_pipes(char *str)
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
		if (str[i] == '|' && flag == 0)
			count++;
		else
			count = 0;
		if (count > 2)
			return (0);
		i++;
	}
	return (1);
}

int check_line_correctness(char *str)
{
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
