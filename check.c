/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:23:32 by abalasub          #+#    #+#             */
/*   Updated: 2024/03/01 17:25:54 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	print_error(void)
{
	ft_printf("\033[31m Erreur : Veuillez les bons paramètres !\033[0m\n\n");
	ft_printf("	=> \033[35m./fractol <mandelbrot>\033[0m\n");
	ft_printf("	=> \033[35m./fractol <julia> [Im] [Re]\033[0m\n");
	ft_printf("	=> \033[35m./fractol <burningship>\033[0m\n\n");
}

int	check_params(char *param)
{
	int	i;
	int	point;
	int	sign;

	i = 0;
	point = 0;
	sign = 0;
	while (param[i])
	{
		if (i == 0 && param[i] == '-' && !sign)
		{
			sign++;
			i++;
		}
		if (ft_isdigit(param[i]))
			i++;
		else if (param[i] == '.' && !point)
		{
			point++;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int	init_julia(int argc, char **argv, t_data *img)
{
	if (ft_strncmp(argv[1], "julia", 5) == 0 && argv[2] && argv[3])
	{
		if (check_params(argv[2]) && check_params(argv[3]))
		{
			img->fx = ft_atod(argv[2]);
			img->fy = ft_atod(argv[3]);
			return (0);
		}
		return (1);
	}
	else if (ft_strncmp(argv[1], "julia", 5) != 0 && argc == 2)
		return (0);
	return (1);
}

int	check_fract(char *str)
{
	char	*fractales[3];
	int		i;

	fractales[0] = "julia";
	fractales[1] = "mandelbrot";
	fractales[2] = "burningship";
	i = 0;
	while (fractales[i])
	{
		if (ft_strncmp(str, fractales[i], ft_strlen(fractales[i])) == 0)
			return (1);
		i++;
	}
	return (0);
}
