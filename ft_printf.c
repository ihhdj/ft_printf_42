/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:50:08 by ihhadjal          #+#    #+#             */
/*   Updated: 2024/11/17 14:02:04 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list arg, const char str)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += ft_print_char(va_arg(arg, int));
	else if (str == 's')
		count += ft_print_str(va_arg(arg, char *));
	else if (str == 'p')
		count += ft_print_pointer(va_arg(arg, void *));
	else if (str == 'd')
		count += ft_print_decimal(va_arg(arg, int));
	else if (str == 'i')
		count += ft_print_decimal(va_arg(arg, int));
	else if (str == 'u')
		count += ft_print_unsigned(va_arg(arg, int));
	else if (str == 'x')
		count += ft_print_hex(va_arg(arg, int));
	else if (str == 'X')
		count += ft_print_hex(va_arg(arg, int));
	else if (str == '%')
		count += ft_print_percent();
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		count;

	va_start(arg, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_format(arg, str[i]);
			i++;
		}
		else
			count += ft_print_char(str[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
