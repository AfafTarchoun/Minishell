/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:38:00 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/27 01:38:34 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

void	free_cmd(t_cmd **cmd)
{
	t_cmd	*temp;

	temp = *cmd;
	while (*cmd)
	{
		*cmd = (*cmd)->next;
		if (temp->tok->value)
			free(temp->tok->value);
		if (temp->tok)
			free(temp->tok);
		free(temp);
		temp = *cmd;
	}
}

void	free_cmd_ws(t_cmd **cmd)
{
	t_cmd	*temp;

	temp = *cmd;
	while (*cmd)
	{
		*cmd = (*cmd)->next;
		free(temp);
		temp = *cmd;
	}
}
