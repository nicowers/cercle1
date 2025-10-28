/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndebavel <ndebavel@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:12:42 by ndebavel          #+#    #+#             */
/*   Updated: 2025/10/28 10:41:43 by ndebavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_format(char c, va_list args);
int	ft_printf(const char *str, ...);
int	ft_putchar_count(char c);
int	ft_putstr_count(char *s);
int	ft_putnbr_count(int nb);
int	ft_unsignedint_count(unsigned int nb);
int	ft_hexa_lower(int nb);
int	ft_hexa_upper(int nb);
int	ft_putnbr_hexa(unsigned int nb, int lower_upper);
int	ft_putnbr_hexa_long(unsigned long nb, int lower_upper);
int	ft_putptr(void *ptr);
#endif