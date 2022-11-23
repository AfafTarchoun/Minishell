/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:43:45 by achahdan          #+#    #+#             */
/*   Updated: 2021/11/16 17:56:25 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	nb_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*fill(int size, int i, long n, long nb)
{
	char	*nbr;

	nbr = (char *)malloc(sizeof(char) * (size + 1));
	if (!nbr)
		return (NULL);
	nbr[size] = '\0';
	size--;
	while (size >= i)
	{
		nbr[size] = (n % 10) + 48;
		size--;
		n = n / 10;
	}
	if (nb < 0)
		nbr[size] = '-';
	return (nbr);
}

char	*ft_itoa(int nx)
{
	char	*nbr;
	int		size;
	int		i;
	long	nb;
	long	n;

	n = (long)nx;
	nb = n;
	i = 0;
	size = nb_len(n);
	if (n < 0)
	{
		n = n * -1;
		size++;
		i = 1;
	}
	nbr = fill(size, i, n, nb);
	return (nbr);
}	
