/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:24:37 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 23:25:01 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	free_token(t_token **cmd)
{
	t_token	*temp;

	temp = *cmd;
	while (*cmd)
	{
		*cmd = (*cmd)->next;
		if (temp->value)
		{
			free(temp->value);
			free(temp);
		}
		else
			free(temp);
		temp = *cmd;
	}
}

void	free_token_ws(t_token **cmd)
{
	t_token	*temp;

	temp = *cmd;
	while (*cmd)
	{
		free(temp->value);
		*cmd = (*cmd)->next;
		free(temp);
		temp = *cmd;
	}
}
