/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:21:06 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/25 20:23:09 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

char	*replace_char(char *str, char ori, char rep)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ori)
			str[i] = rep;
		i++;
	}
	return (str);
}
