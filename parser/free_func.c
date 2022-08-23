/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:38:00 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/23 22:33:18 by atarchou         ###   ########.fr       */
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
		free(temp->tok->value);
		free(temp->tok);
		free(temp);
		temp = *cmd;
	}
}
