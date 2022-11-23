/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:27:26 by achahdan          #+#    #+#             */
/*   Updated: 2021/11/16 18:02:35 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		fi;
	char	c_char;

	c_char = (char)c;
	i = 0;
	fi = -1;
	if (c_char == 0)
		return ((char *)(s + ft_strlen(s)));
	while (s[i])
	{
		if (s[i] == c_char)
			fi = i;
		i++;
	}
	if (fi != -1)
		return ((char *)&s[fi]);
	return (NULL);
}
