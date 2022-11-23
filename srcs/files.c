/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:23:36 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 23:12:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	check_if_input(char *str)
{
	if (ft_strcmp(str, "<") == 0)
		return (1);
	else if (ft_strcmp(str, "<<") == 0)
		return (3);
	return (0);
}

int	check_if_output(char *str)
{
	if (ft_strcmp(str, ">") == 0)
		return (4);
	else if (ft_strcmp(str, ">>") == 0)
		return (2);
	return (0);
}

t_token	*flag_input_files(t_token *tok)
{
	t_token	*head;

	head = tok;
	while (tok)
	{
		if (tok->next)
		{
			if (check_if_input(tok->value) != 0)
			{
				tok->file = check_if_input(tok->value);
				tok->next->file = check_if_input(tok->value);
				tok = tok->next;
			}
		}
		tok = tok->next;
	}
	return (head);
}

t_token	*flag_output_files(t_token *tok)
{
	t_token	*head;

	head = tok;
	while (tok)
	{
		if (tok->next)
		{
			if (check_if_output(tok->value) != 0)
			{
				tok->file = check_if_output(tok->value);
				tok->next->file = check_if_output(tok->value);
				tok = tok->next;
			}
		}
		tok = tok->next;
	}
	return (head);
}

t_token	*init_files_values(t_token *tok)
{
	t_token	*head;

	head = tok;
	while (tok)
	{
		tok->file = 0;
		tok = tok->next;
	}
	return (head);
}
