/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:13:16 by ihhadjal          #+#    #+#             */
/*   Updated: 2024/11/20 10:13:21 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_fd(void *ptr, int fd)
{
	unsigned long long	addr;
	int					count;

	addr = (unsigned long long)ptr;
	count = 0;
	if (!ptr)
	{
		count += ft_putstr_fd("(nil)", fd);
		return (count);
	}
	count += ft_putstr_fd("0x", fd);
	count += ft_puthex_fd(addr, fd, 0);
	return (count);
}
