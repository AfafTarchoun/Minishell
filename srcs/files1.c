/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:25:40 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 23:23:43 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

t_token	*handle_flaggin_files(t_token *tok)
{
	tok = init_files_values(tok);
	tok = flag_output_files(tok);
	tok = flag_input_files(tok);
	return (tok);
}

int	get_mode(int file)
{
	if (file == 2)
		return (APP);
	else if (file == 1)
		return (IN);
	return (NEW);
}

t_name	*add_name(t_name *add, int mode, char *name)
{
	add->f_mode = mode;
	add->name = ft_strdup(name);
	return (add);
}

void	file_collection(t_token *tok, t_name **prev, t_name **lst)
{
	*lst = add_name(*lst, get_mode(tok->file), tok->value);
	(*lst)->next = (t_name *)malloc(sizeof(t_name));
	*prev = *lst;
	*lst = (*lst)->next;
}

void	def_file_end(t_name **prev, t_name **lst)
{
	if (*lst)
	{
		(*prev)->next = NULL;
		free(*lst);
	}
}
