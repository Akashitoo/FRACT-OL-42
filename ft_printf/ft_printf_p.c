/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:46:14 by abalasub          #+#    #+#             */
/*   Updated: 2023/12/19 21:04:33 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_uputnbr_hex(unsigned long int nb, char *base)
{
	if (nb == 0)
		return (ft_putchar('0'));
	else if ((nb / 16) != 0)
		return (ft_uputnbr_hex((nb / 16), base) + ft_putchar(base[nb % 16]));
	else if ((nb / 16) == 0 && (nb % 16) != 0)
		return (ft_putchar(base[nb % 16]));
	return (0);
}

int	putadress(void *p)
{
	uintptr_t	test;

	test = (uintptr_t) p;
	if (p == NULL)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_uputnbr_hex(test, "0123456789abcdef"));
}
