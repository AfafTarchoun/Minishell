/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:11:19 by achahdan          #+#    #+#             */
/*   Updated: 2022/10/03 22:09:39 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	pwd(void)
{
	char	*pwd;

	pwd = NULL;
	pwd = getcwd(pwd, PATH_MAX);
	g_data.exit_code = 0;
	if (!pwd)
	{
		printf("minishell: directory does not exist\n");
		g_data.exit_code = 1;
		return ;
	}
	printf("%s\n", pwd);
	free(pwd);
}
