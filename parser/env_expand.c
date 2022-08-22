/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:09:23 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/22 11:25:18 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

char	*find_str_env(char *str)
{
	char	*env;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			while (str[i] != ' ' && str[i])
			{
				len++;
				i++;
			}
			break ;
		}
		i++;
	}
	env = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			while (str[i] != ' ' && str[i])
			{
				env[len] = str[i];
				len++;
				i++;
			}
			break ;
		}
		i++;
	}
	env[len] = '\0';
	return (env);
}

char	*replace_env(char *str, char *find, char *replace)
{
	char	*result;
	int		i;
	int		count;
	int		newlen;
	int		oldlen;

	count = 0;
	newlen = ft_strlen(replace);
	oldlen = ft_strlen(find);
	i = 0;
	while (str[i])
	{
		if (ft_strstr(&str[i], find) == &str[i])
		{
			count++;
			i += oldlen - 1;
		}
		i++;
	}
	result = (char *)malloc(i + count * (newlen - oldlen) + 1);
	i = 0;
	while (*str)
	{
		if (ft_strstr(str, find) == str)
		{
			ft_strcpy(&result[i], replace);
			i += newlen;
			str += oldlen;
		}
		else
			result[i++] = *str++;
	}
	result[i] = '\0';
	return (result);
}

char	*expand_env_word(char *str, char quote, t_exec *exec)
{
	char	*tmp;

	if (quote != '\'')
	{
		tmp = str;
		// str = ft_strdup("/EXPAND/");
		str = ft_expand(str, exec->envp);
		free(tmp);
	}
	return (str);
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
			tmp = env;
			// env = ft_strdup("EXPAND/EXAMPLE/LOL");
			env = ft_expand(env, exec->envp);
			str = replace_env(str, tmp, env);
			free(tmp);
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
	while (ft_isalnum(lexer->c) || lexer->c == '$')
	{
		str = lx_getchar_as_str(lexer);
		value = ft_realloc(value, ft_strlen(value)
				+ ft_strlen(str) + 1 * sizeof(char));
		ft_strcat(value, str);
		lx_advance(lexer);
	}
	if (find_char_index(value, '$') != -2)
		value = expand_env_word(value, 0, exec);
	return (init_token(WORD, value, 0));
}
