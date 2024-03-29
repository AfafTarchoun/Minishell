/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:15:19 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/05 17:52:00 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

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
			while ((str[i] == '?' || ft_isalnum(str[i])) && str[i])
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
	int		lens_i[5];

	lens_i[1] = ft_strlen(replace);
	lens_i[2] = ft_strlen(find);
	lens_i[3] = 0;
	lens_i[0] = get_count(str, find, &lens_i[3]);
	result = (char *)malloc(lens_i[3] + lens_i[0]
			* (lens_i[1] - lens_i[2]) + 1);
	lens_i[3] = 0;
	lens_i[4] = 0;
	while (*str)
	{
		if (ft_strstr(str, find) == str && lens_i[4] == 0)
		{
			lens_i[4] = 1;
			ft_strcpy(&result[lens_i[3]], replace);
			lens_i[3] += lens_i[1];
			str += lens_i[2];
		}
		else
			result[lens_i[3]++] = *str++;
	}
	result[lens_i[3]] = '\0';
	return (result);
}

char	*expand_env_word(char *str, char quote, t_env *env_lst)
{
	char	*tmp;

	if (str[1] != '\0')
	{
		if (quote != '\'')
		{
			tmp = str;
			str = expand_key(str, env_lst);
			free(tmp);
		}
	}
	return (str);
}
