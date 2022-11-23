/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:46:48 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 21:45:19 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstrrrr(char *str, int *len)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putcharrrrrr(str[i++], len);
}
