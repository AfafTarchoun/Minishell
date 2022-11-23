/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:40:25 by achahdan          #+#    #+#             */
/*   Updated: 2022/10/03 22:09:39 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	is_valid_flag(char *str)
{
	int	i;

	if (str[0] != '-')
		return (-1);
	i = 1;
	if (str[i] == 0)
		return (-1);
	while (str[i])
	{
		if (str[i] != 'n')
			return (-1);
		i++;
	}
	return (1);
}

void	print_echo(char	**args, int i, int new_line)
{
	if (args[i] == 0)
		return ;
	while (args[i])
	{
		ft_printf("%s", args[i]);
		if (args[i + 1])
			ft_printf(" ");
		i++;
	}
	if (new_line)
		ft_printf("\n");
}

void	echo(t_cmd *cmd)
{
	char	**args;
	int		i;
	int		new_line;

	args = cmd->args + 1;
	if (!*args)
	{
		ft_printf("\n");
		return ;
	}
	g_data.exit_code = 0;
	i = 0;
	new_line = 1;
	while (args[i])
	{
		if (is_valid_flag(args[i]) == 1)
			i++;
		else
			break ;
	}
	if (i > 0)
		new_line = 0;
	print_echo(args, i, new_line);
}
