/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:20:03 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/05 17:13:07 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	handle_env_replace(char **str, char *env, int flag, t_env *env_lst)
{
	char	*tmp;
	char	*placeholder;

	tmp = env;
	if (flag == 1)
		env = expand_key(env, env_lst);
	else if (flag == 0)
		env = ft_strdup("\200");
	placeholder = *str;
	*str = replace_env(*str, tmp, env);
	free(tmp);
	free(env);
	free(placeholder);
}

char	*handle_num_env(char *str)
{
	char	*result;
	int		len;
	int		i;
	int		j;

	len = (int)ft_strlen(str);
	result = (char *)malloc(sizeof(char) * (len - 2) + 1);
	i = 2;
	j = 0;
	while (str[i])
	{
		result[j] = str[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}

void	handle_num_replace(char **str, char *tmp, char *env)
{
	char	*placeholder;

	placeholder = *str;
	*str = replace_env(*str, tmp, env);
	free(env);
	free(placeholder);
}
