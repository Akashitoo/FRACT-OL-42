/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:46:14 by abalasub          #+#    #+#             */
/*   Updated: 2023/12/19 21:02:20 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_uputnbr(unsigned int nb)
{
	if (nb > 9)
	{
		return (ft_uputnbr(nb / 10) + ft_uputnbr (nb % 10));
	}
	else if (nb < 10)
	{
		return (ft_putchar('0' + nb));
	}
	return (0);
}
