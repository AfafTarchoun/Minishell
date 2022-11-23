/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:17:21 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/05 17:25:55 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	env_special_case1(char **str, char *env)
{
	char	*tmp;

	if (env[1] == '?')
	{
		free(env);
		tmp = *str;
		*str = ft_itoa(g_data.exit_code);
		free(tmp);
	}
}

void	env_special_case2(char **str, char *env)
{
	char	*tmp;

	if (ft_isdigit(env[1]))
	{
		tmp = env;
		env = handle_num_env(env);
		handle_num_replace(str, tmp, env);
		free(tmp);
	}
}

char	*expand_env(char *str, char quote, t_env *env_lst)
{
	char	*env;

	if (quote == '\"')
	{
		while (find_char_index(str, '$') != -2)
		{
			env = find_str_env(str);
			if (env[1] == '?')
				env_special_case1(&str, env);
			else if (ft_isdigit(env[1]))
				env_special_case2(&str, env);
			else if (env[1] != '\0')
				handle_env_replace(&str, env, 1, env_lst);
			else
				handle_env_replace(&str, env, 0, env_lst);
		}
		str = replace_char(str, '\200', '$');
	}
	return (str);
}

void	env_weird_cases(char **value, t_env *env_lst)
{
	char	*str;
	char	*tmp;

	str = *value;
	tmp = NULL;
	if (ft_isdigit(str[1]))
	{
		tmp = str;
		*value = handle_num_env(*value);
		free(tmp);
	}
	if (str[1] == '?')
	{
		tmp = str;
		*value = ft_itoa(g_data.exit_code);
		free(tmp);
	}
	else
		*value = expand_env_word(*value, 0, env_lst);
}

t_values	*lx_collect_env(t_lexer *lexer, t_env *env_lst)
{
	char	*value;
	char	*str;

	value = (char *)malloc(sizeof(char));
	value[0] = '\0';
	collect_process(&str, &value, lexer);
	if (lexer->c == '?')
		collect_process(&str, &value, lexer);
	else
	{
		while (lexer->c == '_')
			collect_process(&str, &value, lexer);
		while (ft_isalnum(lexer->c))
			collect_process(&str, &value, lexer);
	}
	if (find_char_index(value, '$') != -2)
		env_weird_cases(&value, env_lst);
	return (init_values(OTHER, value, 0));
}
