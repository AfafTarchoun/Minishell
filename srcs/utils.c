/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:31:10 by achahdan          #+#    #+#             */
/*   Updated: 2022/10/03 23:27:19 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	free_2d_array(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	cmd_lst_len(t_cmd *cmds)
{
	int	i;

	i = 0;
	while (cmds)
	{
		i++;
		cmds = cmds->next;
	}
	return (i);
}

char	*ft_readlinee(char *prompt)
{
	char	*line;

	ft_putstr_fd(prompt, 1);
	line = get_next_line(0);
	if (!line)
		return (NULL);
	line[ft_strlen(line) - 1] = 0;
	return (line);
}

int	ft_freee(void *ptr, int ret)
{
	free(ptr);
	return (ret);
}

int	check_malloc(void *to_be_checked, void *to_be_freed, int is_exit)
{
	if (to_be_checked)
		return (0);
	free(to_be_freed);
	ft_perror("minishell", NULL, 0);
	g_data.exit_code = 1;
	if (is_exit)
		exit (1);
	return (-1);
}
