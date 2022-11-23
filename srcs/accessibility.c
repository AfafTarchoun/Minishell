/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessibility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:34:49 by achahdan          #+#    #+#             */
/*   Updated: 2022/10/03 23:27:19 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	*check_path(char *cmd, t_env *env)
{
	char	**paths;
	char	*temp;
	char	*path_env;

	while (env)
	{
		if (!ft_strcmp(env->var, "PATH"))
			break ;
		env = env->next;
	}
	if (!*cmd || env == NULL || env->value == NULL)
		return (NULL);
	paths = ft_split(env->value, ':');
	while (*paths)
	{
		temp = ft_strjoin(*paths, "/");
		path_env = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path_env, F_OK) == 0)
			return (path_env);
		paths++;
		free(path_env);
	}
	return (NULL);
}
