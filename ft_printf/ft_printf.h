/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:12:02 by atarchou          #+#    #+#             */
/*   Updated: 2022/10/03 21:45:19 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_putcharrrrrr(char c, int *len);
void	ft_putstrrrr(char *str, int *len);
void	ft_putnbrrrr(int nb, int *len);
void	ft_putnbr_unsigned(unsigned int nb, int *len);
void	ft_print_hexa_lower(unsigned int nb, int *len);
void	ft_print_hexa_upper(unsigned int nb, int *len);
void	ft_print_hexa_address(unsigned long nb, int *len);
void	ft_print_address(unsigned long address, int *len);
int		ft_printf(const char *format, ...);

#endif
