/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:54:20 by abalasub          #+#    #+#             */
/*   Updated: 2023/12/20 13:50:30 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	check_flag(va_list parameters, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
			count += ft_putchar((char)va_arg(parameters, int));
	else if (c == 's')
			count += ft_putstr((char *) va_arg(parameters, char *));
	else if (c == '%')
			count += ft_putchar('%');
	else if (c == 'd' || c == 'i')
			count += ft_putnbr((int) va_arg(parameters, int));
	else if (c == 'u')
			count += ft_uputnbr((unsigned int) va_arg(parameters,
					unsigned int));
	else if (c == 'x')
			count += ft_putnbr_hex((int) va_arg(parameters, int),
				"0123456789abcdef");
	else if (c == 'X')
			count += ft_putnbr_hex((int) va_arg(parameters, int),
				"0123456789ABCDEF");
	else if (c == 'p')
			count += putadress((void *)va_arg(parameters, void *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	parameters;
	int		i;
	int		count;

	va_start(parameters, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += check_flag(parameters, format[i + 1]);
			i++;
		}
		else if (format[i] != '%')
		{
			count += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(parameters);
	return (count);
}
