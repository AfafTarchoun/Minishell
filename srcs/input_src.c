/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_src.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:25:43 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 23:26:11 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

t_cmd	*fill_input_source(t_cmd *cmds)
{
	t_cmd	*head;
	t_name	*tmp;

	head = cmds;
	tmp = cmds->files;
	while (cmds)
	{
		cmds->input_source = STDIN;
		if (cmds->heredoc_lst)
			cmds->input_source = HEREDOC;
		else if (tmp)
		{
			while (tmp)
			{
				if (tmp->f_mode == IN)
				{
					cmds->input_source = INFILE;
					break ;
				}
					tmp = tmp->next;
			}
		}
		cmds = cmds->next;
	}
	return (head);
}
