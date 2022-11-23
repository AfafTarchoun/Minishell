/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:52:05 by achahdan          #+#    #+#             */
/*   Updated: 2021/11/17 19:24:57 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_in_set(char c, char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	first_index(char const *str, char const *set)
{
	int	i;

	i = 0;
	while (str[i] && is_in_set(str[i], set) == 1)
	{
		i++;
	}
	return (i);
}

static int	last_index(char const *str, char const *set)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0 && is_in_set(str[i], set) == 1)
	{
		i--;
	}
	return (i);
}

static int	count_len(int start, int end, char const *str)
{
	int	count;

	count = 0;
	while (start <= end && str[start])
	{
		count++;
		start++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		size;
	char	*ptr;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	start = first_index(s1, set);
	end = last_index(s1, set);
	size = count_len(start, end, s1);
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	while (start <= end)
	{
		ptr[i] = (char)(s1[start]);
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}
