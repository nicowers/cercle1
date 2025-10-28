/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndebavel <ndebavel@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:29:16 by ndebavel          #+#    #+#             */
/*   Updated: 2025/10/28 10:44:31 by ndebavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_lower(int nb)
{
	int	c;

	c = 0;
	if (nb >= 10 && nb <= 15)
	{
		c = nb + 'a' - 10;
		write(1, &c, 1);
	}
	else
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	return (1);
}

int	ft_hexa_upper(int nb)
{
	int	c;

	c = 0;
	if (nb >= 10 && nb <= 15)
	{
		c = nb + 'A' - 10;
		write(1, &c, 1);
	}
	else
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	return (1);
}

int	ft_putnbr_hexa(unsigned int nb, int lower_upper)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_putnbr_hexa(nb / 16, lower_upper);
		count += ft_putnbr_hexa(nb % 16, lower_upper);
	}
	if (nb < 16)
	{
		if (lower_upper == 0)
			count += ft_hexa_lower(nb);
		else
			count += ft_hexa_upper(nb);
	}
	return (count);
}

int	ft_putnbr_hexa_long(unsigned long nb, int lower_upper)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_putnbr_hexa_long(nb / 16, lower_upper);
		count += ft_putnbr_hexa_long(nb % 16, lower_upper);
	}
	if (nb < 16)
	{
		if (lower_upper == 1)
			count += ft_hexa_lower(nb);
		else
			count += ft_hexa_upper(nb);
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_putstr_count("(nil)"));
	ft_putstr_count("0x");
	count += 2;
	count += ft_putnbr_hexa_long((unsigned long)ptr, 1);
	return (count);
}
