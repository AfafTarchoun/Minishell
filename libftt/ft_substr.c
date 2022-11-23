/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:35:41 by achahdan          #+#    #+#             */
/*   Updated: 2021/11/18 15:09:05 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	size_t			i;
	unsigned int	l;

	i = start;
	l = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	while (s[i++] && l < len)
		l++;
	p = malloc(sizeof(char) * (l + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (i < l)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = 0;
	return (p);
}
