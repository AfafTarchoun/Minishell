/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:09:23 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/24 09:32:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

int	get_env_size(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			len++;
			i++;
			while (ft_isalnum(str[i]) && str[i])
			{
				len++;
				i++;
			}
			break ;
		}
		i++;
	}
	return (len);
}

char	*find_str_env(char *str)
{
	char	*env;
	int		i;
	int		len;

	i = 0;
	len = get_env_size(str);
	env = (char *)malloc(sizeof(char) * len + 1);
	len = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			env[len++] = str[i++];
			while (ft_isalnum(str[i]) && str[i])
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

int	get_count(char *str, char *find, int *io)
{
	int	i;
	int	count;
	int	oldlen;

	count = 0;
	i = *io;
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
	*io = i;
	return (count);
}

char	*replace_env(char *str, char *find, char *replace)
{
	char	*result;
	int		i;
	int		lens[3];

	lens[0] = 0;
	lens[1] = ft_strlen(replace);
	lens[2] = ft_strlen(find);
	i = 0;
	lens[0] = get_count(str, find, &i);
	result = (char *)malloc(i + lens[0] * (lens[1] - lens[2]) + 1);
	i = 0;
	while (*str)
	{
		if (ft_strstr(str, find) == str)
		{
			ft_strcpy(&result[i], replace);
			i += lens[1];
			str += lens[2];
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
		str = ft_expand(str, exec->envp);
		free(tmp);
	}
	return (str);
}
