/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndebavel <ndebavel@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 09:37:16 by ndebavel          #+#    #+#             */
/*   Updated: 2025/11/12 10:17:01 by ndebavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_count(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr_count(va_arg(args, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_count(va_arg(args, int)));
	if (c == 'u')
		return (ft_unsignedint_count(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_putnbr_hexa(va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (ft_putnbr_hexa(va_arg(args, unsigned int), 1));
	if (c == '%')
		return (ft_putchar_count('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			count += ft_format(str[i + 1], args);
			i += 2;
		}
		else
		{
			count += ft_putchar_count(str[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}

int main(void)
{
	unsigned int nb = 41254645;
	char str[50] = "j adore ce nombre";

	ft_printf("%s %u\n", str, nb);
	printf("%s %u\n", str, nb);
}