/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:58:06 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/28 21:03:14 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

char	*ft_expand(char *expand, char **envp)
{
	int		i;
	char	*xtemp;

	i = 0;
	if (expand[0] != '$')
		return (ft_mystrdup(expand, 0));
	if (expand != NULL)
	{
		while (envp[i])
		{
			xtemp = ft_get_expand_env(envp[i]);
			if (ft_strcmp(expand + 1, xtemp) == 0)
			{
				free(xtemp);
				return (ft_mystrdup(envp[i]
						+ ft_find_last_character(envp[i], '=') + 1, 0));
			}
				i++;
			free(xtemp);
		}
	}
	return (ft_mystrdup("", 0));
}

void	handle_env_replace(char **str, char *env, int flag, t_exec *exec)
{
	char	*tmp;
	char	*placeholder;

	tmp = env;
	if (flag == 1)
		env = ft_expand(env, exec->envp);
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

	len = ft_strlen(str);
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

char	*expand_env(char *str, char quote, t_exec *exec)
{
	char	*tmp;
	char	*env;

	if (quote == '\"')
	{
		while (find_char_index(str, '$') != -2)
		{
			env = find_str_env(str);
			if (ft_isdigit(env[1]))
			{
				tmp = env;
				env = handle_num_env(env);
				handle_num_replace(&str, tmp, env);
				free(tmp);
			}
			else if (env[1] != '\0')
				handle_env_replace(&str, env, 1, exec);
			else
				handle_env_replace(&str, env, 0, exec);
		}
		str = replace_char(str, '\200', '$');
	}
	return (str);
}
