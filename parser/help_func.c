/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:56:55 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/22 10:07:33 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (!size)
		return (ptr);
	new_ptr = malloc(size);
	memcpy(new_ptr, ptr, size);
	return (new_ptr);
}

int	find_char_index(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-2);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-2);
}

char	*remove_char(char *str, char charToRemmove)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = strlen(str);
	while (i < len)
	{
		if (str[i] == charToRemmove)
		{
			j = i;
			while (j < len)
			{
				str[j] = str[j + 1];
				j++;
			}
			len--;
			i--;
		}
		i++;
	}
	return (str);
}

int	count_words(char *str)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if ((str[i] != ' ' && str[i + 1] == ' ')
			|| (str[i + 1] == '\0' && str[i] != ' '))
			words++;
		i++;
	}
	return (words);
}

void	delete_node(t_cmd **head, t_cmd *prev)
{
	t_cmd	*temp;

	temp = *head;
	if (temp != NULL)
	{
		*head = temp->next;
		prev->next = *head;
		free(temp);
	}
}
