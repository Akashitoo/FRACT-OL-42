/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:46:14 by abalasub          #+#    #+#             */
/*   Updated: 2023/12/19 21:03:49 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int nb, char *base)
{
	if (nb == 0)
		return (ft_putchar('0'));
	else if ((nb / 16) != 0)
		return (ft_putnbr_hex((nb / 16), base) + ft_putchar(base[nb % 16]));
	else if ((nb / 16) == 0 && (nb % 16) != 0)
		return (ft_putchar(base[nb % 16]));
	return (0);
}
