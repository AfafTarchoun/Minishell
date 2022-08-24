/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:58:06 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/24 09:34:23 by atarchou         ###   ########.fr       */
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

char	*expand_env(char *str, char quote, t_exec *exec)
{
	char	*tmp;
	char	*env;
	char	*placeholder;

	if (quote == '\"')
	{
		while (find_char_index(str, '$') != -2)
		{
			env = find_str_env(str);
			tmp = env;
			env = ft_expand(env, exec->envp);
			placeholder = str;
			str = replace_env(str, tmp, env);
			free(tmp);
			free(env);
			free(placeholder);
		}
	}
	return (str);
}

t_token	*lx_collect_env(t_lexer *lexer, t_exec *exec)
{
	char	*value;
	char	*str;

	value = (char *)malloc(sizeof(char) + 1);
	value[0] = '\0';
	str = lx_getchar_as_str(lexer);
	value = ft_realloc(value, ft_strlen(value)
			+ ft_strlen(str) + 1 * sizeof(char));
	ft_strcat(value, str);
	free(str);
	lx_advance(lexer);
	while (ft_isalnum(lexer->c))
	{
		str = lx_getchar_as_str(lexer);
		value = allocate(value, str);
		ft_strcat(value, str);
		free(str);
		lx_advance(lexer);
	}
	if (find_char_index(value, '$') != -2)
		value = expand_env_word(value, 0, exec);
	return (init_token(WORD, value, 0));
}
