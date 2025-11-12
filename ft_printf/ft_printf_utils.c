/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndebavel <ndebavel@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:46:18 by ndebavel          #+#    #+#             */
/*   Updated: 2025/11/12 10:09:34 by ndebavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_count(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_count(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_count(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
		return (count);
	}
	if (nb < 0)
	{
		count += ft_putchar_count('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		count += ft_putnbr_count(nb / 10);
		count += ft_putnbr_count(nb % 10);
	}
	else
		count += ft_putchar_count(nb + '0');
	return (count);
}

int	ft_unsignedint_count(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_putnbr_count(nb / 10);
	count += ft_putchar_count(nb % 10 + '0');
	return (count);
}
