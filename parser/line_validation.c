/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:16:29 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/25 20:24:31 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"


int validate_rep_pipe(char *str)
{
  int i;
  int count;

  i = 0;
  count = 0;
  while (str[i])
  {
    if (str[i] == '\"' || str[i] == '\'')
      count++;
    if (count == 2)
      count = 0;
    if (count == 0)
    {
      if (str[i] == '|')
      {
        i++;
        while (str[i] == ' ')
          i++;
        if (!ft_isalnum(str[i]))
            return (0);
        else if (!ft_isalnum(str[i]))
          return (0);
      }
    }
    i++;
  }
  return (1);
}

int	handle_repitition(char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
	if (!ft_isalnum(str[*i]))
		return (0);
	else if (!ft_isalnum(str[*i]))
		return (0);
	return (1);
}

int validate_rep_redir(char *str, char redir)
{
  int i;
  int count;

  i = 0;
  count = 0;
  while (str[i])
  {
    if (str[i] == '\"' || str[i] == '\'')
      count++;
    if (count == 2)
      count = 0;
    if (count == 0)
    {
      if (str[i] == redir && str[i + 1] != redir)
      {
        i++;
        if (handle_repitition(str, &i) == 0)
          return (0);
      }
      else if (str[i] == redir && str[i + 1] == redir)
      {
        i = i + 2;
        if (handle_repitition(str, &i) == 0)
          return (0);
      }
    }
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
