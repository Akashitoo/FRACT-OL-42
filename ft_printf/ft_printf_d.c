/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:46:14 by abalasub          #+#    #+#             */
/*   Updated: 2023/12/19 21:01:53 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		return (ft_putnbr(-214748364) + ft_putnbr(8));
	}
	else if (nb < 0)
	{
		return (ft_putchar('-') + ft_putnbr(-nb));
	}
	else if (nb > 9)
	{
		return (ft_putnbr(nb / 10) + ft_putnbr(nb % 10));
	}
	else if (nb < 10)
	{
		ft_putchar('0' + nb);
		return (1);
	}
	return (0);
}
