/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:00:08 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 21:48:52 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

char	*get_next_line(int fd);
size_t	ft_strlenn(const char *s);
char	*ft_strchrr(const char *s, int c);
char	*ft_strjoinn(char const *s1, char const *s2);
size_t	ft_strlcpyy(char *dst, const char *src, size_t dstsize);
char	*get_line(char *s);
char	*get_remaine(char *s);

#endif