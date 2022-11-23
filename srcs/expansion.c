/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:02:17 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/05 19:53:02 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	*expand_key(char *env_var, t_env *lst)
{
	char	*value;
	char	*tmp;

	tmp = ft_strdup(env_var);
	tmp = remove_char(tmp, '$');
	while (lst)
	{
		if (ft_strcmp(tmp, lst->var) == 0)
		{
			value = ft_strdup(lst->value);
			free(tmp);
			return (value);
		}
		lst = lst->next;
	}
	free(tmp);
	return (ft_strdup("\0"));
}

char	*add_key(char *envp)
{
	int		i;
	char	*str;

	i = 0;
	while (envp[i] && envp[i] != '=')
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (envp[i] && envp[i] != '=')
	{
		str[i] = envp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*add_value(char *envp)
{
	int		i;
	int		size;
	int		flag;
	char	*str;

	i = 0;
	while (envp[i] && envp[i] != '=')
		i++;
	i++;
	flag = i;
	size = 0;
	while (envp[i])
	{
		size++;
		i++;
	}
	str = (char *)malloc(sizeof(char) * size + 1);
	i = flag;
	size = 0;
	while (envp[i])
		str[size++] = envp[i++];
	str[size] = '\0';
	return (str);
}

t_env	*env_to_list(char **envp)
{
	t_env	*env_list;
	t_env	*head;
	int		i;

	env_list = (t_env *)malloc(sizeof(t_env));
	env_list->var = add_key(envp[0]);
	env_list->value = add_value(envp[0]);
	head = env_list;
	i = 1;
	while (i < get_size_envp(envp))
	{
		if (i + 1 == get_size_envp(envp))
			env_list->next = NULL;
		else
			env_list->next = (t_env *)malloc(sizeof(t_env));
		if (!env_list->var)
		{
			env_list->var = add_key(envp[i]);
			env_list->value = add_value(envp[i]);
		}
		env_list = env_list->next;
		i++;
	}
	return (head);
}

char	**copy_envp(char **envp)
{
	char	**copy;
	int		size;
	int		i;

	size = get_size_envp(envp);
	copy = (char **)malloc(sizeof(char *) * size + 1);
	i = 0;
	while (i < size)
	{
		copy[i] = ft_strdup(envp[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
