/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:55:04 by achahdan          #+#    #+#             */
/*   Updated: 2022/10/03 23:27:19 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	ft_redisplay(void)
{
	g_data.exit_code = 1;
	ft_putstr_fd("\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	sig_int_handler(int sig)
{
	if (g_data.loc == PROMPT)
		ft_redisplay();
	else if (g_data.loc == EXEC)
	{
		ft_putstr_fd("^C\n", 1);
		rl_replace_line("", 0);
		rl_redisplay();
		if (!g_data.last_cmd_returned)
		{
			g_data.exit_code = 128 + sig;
			g_data.sig_caught = 1;
		}
	}
	else
	{
		g_data.sig_caught = 1;
		ft_putstr_fd("\n", 1);
		close(0);
		g_data.exit_code = 1;
	}
}

void	sig_quit_handler(int sig)
{
	(void) sig;
	rl_on_new_line();
	if (g_data.loc == PROMPT)
		rl_redisplay();
	else if (g_data.loc == EXEC)
	{
		if (!g_data.last_cmd_returned)
		{
			g_data.exit_code = sig + 128;
			g_data.sig_caught = 1;
		}
		printf("^\\");
		if (cmd_lst_len(g_data.cmds) == 1)
			printf("Quit: 3\n");
	}
}
