/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:13:37 by abalasub          #+#    #+#             */
/*   Updated: 2024/03/01 17:42:06 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	pixel_put_img(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_fractol(t_data *img)
{
	int	x;
	int	y;
	int	result;

	y = 0;
	while (y < 500)
	{
		x = 0;
		while (x < 500)
		{
			if (ft_strncmp(img->fractal, "julia", ft_strlen("julia")) == 0)
				result = julia(x, y, img);
			else if (ft_strncmp(img->fractal, "mandelbrot",
					ft_strlen("mandelbrot")) == 0)
				result = mandelbrot(x, y, img);
			else if (ft_strncmp(img->fractal, "burningship",
					ft_strlen("burningship")) == 0)
				result = burningship(x, y, img);
			pixel_put_img(img, x, y, result);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	display_info(img);
}

void	zoom(double zoom_factor, int x, int y, t_data *img)
{
	double	x1;
	double	y1;
	double	new_largeur;
	double	new_hauteur;

	x1 = img->xmin + ((double)x / 500) * (img->xmax - img->xmin);
	y1 = img->ymin + ((double)y / 500) * (img->ymax - img->ymin);
	if (img->zoom_direction)
	{
		new_largeur = (img->xmax - img->xmin) * zoom_factor;
		new_hauteur = (img->ymax - img->ymin) * zoom_factor;
	}
	else
	{
		new_largeur = (img->xmax - img->xmin) / zoom_factor;
		new_hauteur = (img->ymax - img->ymin) / zoom_factor;
	}
	img->xmin = x1 - new_largeur / 2;
	img->xmax = x1 + new_largeur / 2;
	img->ymin = y1 - new_hauteur / 2;
	img->ymax = y1 + new_hauteur / 2;
	draw_fractol(img);
}

void	print_keybind(void)
{
	ft_printf("\n		\033[1;4;35;47m[GUIDE DES TOUCHES]\033[0m	\n\n");
	ft_printf("	\033[1;4mO/P\033[0m-> Diminuer /");
	ft_printf(" Augmenter la precision \n");
	ft_printf("	\033[1;4mA/Q\033[0m-> Diminuer /");
	ft_printf(" Augmenter la partie reelle (Julia) \n");
	ft_printf("	\033[1;4mS/W\033[0m-> Diminuer /");
	ft_printf(" Augmenter la partie imaginaire (Julia) \n");
	ft_printf("	\033[1;4m C \033[0m-> Changer la palette de couleur \n");
	ft_printf("	\033[1;4m← →\033[0m-> Déplacer la vue horizontalement \n");
	ft_printf("	\033[1;4m↑ ↓\033[0m-> Déplacer la vue verticalement \n\n");
}

void	display_info(t_data *img)
{
	char	*string;
	char	*itoa;

	if (ft_strncmp(img->fractal, "julia",
			ft_strlen("julia")) == 0)
		mlx_string_put(img->mlx, img->win, 220, 25,
			0xFFFFFF, "[ Julia Set ]");
	else if (ft_strncmp(img->fractal, "mandelbrot",
			ft_strlen("mandelbrot")) == 0)
		mlx_string_put(img->mlx, img->win, 200, 25,
			0xFFFFFF, "[ Mandelbrot Set ]");
	else if (ft_strncmp(img->fractal, "burningship",
			ft_strlen("burningship")) == 0)
		mlx_string_put(img->mlx, img->win, 190, 25,
			0xFFFFFF, "[ Burningship Set ]");
	itoa = ft_itoa(img->max_iter);
	string = ft_strjoin("Precision : ", itoa);
	mlx_string_put(img->mlx, img->win, 50, 450, 0xFFFFFF, string);
	free(itoa);
	free(string);
}
