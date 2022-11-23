/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:07:40 by achahdan          #+#    #+#             */
/*   Updated: 2022/10/03 22:09:39 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	list_len(void)
{
	int		count;
	t_env	*ptr;

	count = 0;
	ptr = g_data.env_lst;
	while (ptr)
	{
		if (ptr->value)
			count++;
		ptr = ptr->next;
	}
	return (count + 1);
}

void	fill_env(void)
{
	t_env	*ptr;
	char	*temp;
	char	**env;
	int		i;

	i = 0;
	ptr = g_data.env_lst;
	if (g_data.env)
		free_2d_array(g_data.env);
	env = malloc(sizeof(char *) * list_len());
	while (ptr)
	{
		if (ptr->value)
		{	
			temp = ft_strjoin(ptr->var, "=");
			env[i] = ft_strjoin(temp, ptr->value);
			free(temp);
			i++;
		}
		ptr = ptr->next;
	}
	env[i] = 0;
	g_data.env = env;
}

void	env(void)
{
	t_env	*ptr;

	ptr = g_data.env_lst;
	g_data.exit_code = 0;
	if (sv(ptr, "PATH") == -1)
	{
		printf("minishell: env: No such file or directory\n");
		g_data.exit_code = 127;
		return ;
	}
	while (ptr)
	{
		if (ptr->value[0] != 0)
			printf("%s=%s\n", ptr->var, ptr->value);
		ptr = ptr->next;
	}
}
