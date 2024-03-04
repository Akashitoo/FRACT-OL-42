/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:27:46 by abalasub          #+#    #+#             */
/*   Updated: 2024/02/26 20:28:00 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	sign(char *number)
{
	int	sign;

	sign = 1;
	if (ft_atoi(number) == 0)
	{
		if (number[0] == '-')
			sign = -1;
	}
	return (sign);
}

double	ft_atod(char *number)
{
	double	result;
	double	j;
	int		i;

	result = ft_atoi(number);
	i = 0;
	j = (double)1 / 10;
	while (number[i] && number[i] != '.')
	{
		i++;
	}
	if (number[i] == '.')
	{
		i++;
		while (number[i])
		{
			if (result >= 0)
				result += (number[i] - 48) * j;
			else
				result -= (number[i] - 48) * j;
			j /= 10;
			i++;
		}
	}
	return (result * sign(number));
}
