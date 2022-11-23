/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:48:35 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 22:11:38 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrrrr(int nb, int *len)
{
	char	c;

	if (nb == -2147483648)
	{
		ft_putstrrrr("-2147483648", len);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putcharrrrrr('-', len);
	}
	if (nb < 10)
	{
		c = nb + '0';
		ft_putcharrrrrr(c, len);
	}
	else
	{
		ft_putnbrrrr(nb / 10, len);
		ft_putnbrrrr(nb % 10, len);
	}
}
