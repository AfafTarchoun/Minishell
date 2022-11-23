/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:00:03 by achahdan          #+#    #+#             */
/*   Updated: 2021/11/16 18:18:30 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s1_un;
	unsigned char	*s2_un;

	i = 0;
	s1_un = (unsigned char *)s1;
	s2_un = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (s1_un[i] && s2_un[i] && i < n - 1)
	{
		if (s1_un[i] != s2_un[i])
			break ;
		i++;
	}
	return ((int)(s1_un[i] - s2_un[i]));
}
