/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_upper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:25:02 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 21:45:19 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hexa_upper(unsigned int nb, int *len)
{
	char	c;

	if (nb < 16)
	{
		if (nb < 10)
			c = nb + '0';
		else
			c = nb + 55;
		ft_putcharrrrrr(c, len);
	}
	else
	{
		ft_print_hexa_upper(nb / 16, len);
		ft_print_hexa_upper(nb % 16, len);
	}
}
