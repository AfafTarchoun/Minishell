/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 00:18:28 by achahdan          #+#    #+#             */
/*   Updated: 2022/10/03 23:16:07 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	value_len(char *var, int *i)
{
	int		j;
	char	*tmp;
	t_env	*tmp_env;

	j = 0;
	while (ft_isalnum(var[*i + j]) || var[*i + j] == '_')
		j++;
	tmp = ft_strndup(var + *i, j);
	if (!tmp)
		return (ft_perror("minishell", NULL, 0));
	(*i) += j;
	tmp_env = g_data.env_lst;
	while (tmp_env)
	{
		if (!ft_strcmp(tmp_env->var, tmp))
			break ;
		tmp_env = tmp_env->next;
	}
	j = -1;
	if (tmp_env)
		j += ft_strlen(tmp_env->value);
	j -= ft_strlen(tmp);
	free(tmp);
	return (j);
}

char	*get_value_from_env(char *value, int *i)
{
	int		j;
	char	*tmp;
	t_env	*tmp_env;

	j = 0;
	while (ft_isalnum(value[*i + j]) || value[*i + j] == '_')
		j++;
	tmp = ft_strndup(value + *i, j);
	(*i) += j;
	tmp_env = g_data.env_lst;
	while (tmp_env)
	{
		if (!ft_strcmp(tmp_env->var, tmp))
			break ;
		tmp_env = tmp_env->next;
	}
	free(tmp);
	if (!tmp_env)
		return (NULL);
	return (tmp_env->value);
}

void	check_n_expandd(char *value, char *new, int *i, int *j)
{
	int		k;
	char	*tmp;

	k = 0;
	if (value[*i] == '$' && value[*i + 1] == '?')
	{
		(*i) += 2;
		if (g_data.pipe_found)
			g_data.exit_code = 0;
		tmp = ft_itoa(g_data.exit_code);
		while (tmp[k])
			new[(*j)++] = tmp[k++];
		free(tmp);
	}
	else if (value[*i] == '$' && ft_isalpha(value[*i + 1]))
	{
		(*i)++;
		tmp = get_value_from_env(value, i);
		while (tmp && tmp[k])
			new[(*j)++] = tmp[k++];
	}
	else
		new[(*j)++] = value[(*i)++];
}

void	remove_quotess(char *value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (value[i])
	{
		if (value[i] == '\'')
			while (value[++i] != '\'')
				value[j++] = value[i];
		else if (value[i] == '\"')
			while (value[++i] != '\"')
				value[j++] = value[i];
		else
			value[j++] = value[i];
		i++;
	}
	value[j] = 0;
}

int	get_expansion_len(char *var, int *i)
{
	int	len;

	len = 0;
	if (var[*i] == '?')
	{
		len++;
		(*i)++;
	}
	else if (ft_isalpha(var[*i]))
		len += value_len(var, i);
	return (len);
}
