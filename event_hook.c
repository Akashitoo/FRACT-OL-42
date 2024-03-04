/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:21:59 by abalasub          #+#    #+#             */
/*   Updated: 2024/03/01 16:44:31 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	mouse_hook(int mousecode, int x, int y, t_data *img)
{
	if (mousecode == 4)
	{
		img->zoom_direction = 1;
		zoom(0.8, x, y, img);
	}
	else if (mousecode == 5)
	{
		img->zoom_direction = -1;
		zoom(1.2, x, y, img);
	}
	return (0);
}

int	close_window(t_data *img)
{
	if (img->win)
	{
		mlx_destroy_window(img->mlx, img->win);
		img->win = NULL;
	}
	if (img->img)
	{
		mlx_destroy_image(img->mlx, img->img);
		img->img = NULL;
	}
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	arrow_press(int keycode, t_data *img)
{
	if (keycode == 65363)
	{
		img->xmax = img->xmax + (((img->xmax - img->xmin) / 500) * 10);
		img->xmin = img->xmin + (((img->xmax - img->xmin) / 500) * 10);
	}
	else if (keycode == 65361)
	{
		img->xmax = img->xmax - (((img->xmax - img->xmin) / 500) * 10);
		img->xmin = img->xmin - (((img->xmax - img->xmin) / 500) * 10);
	}
	else if (keycode == 65362)
	{
		img->ymax = img->ymax - (((img->ymax - img->ymin) / 500) * 10);
		img->ymin = img->ymin - (((img->ymax - img->ymin) / 500) * 10);
	}
	else if (keycode == 65364)
	{
		img->ymax = img->ymax + (((img->ymax - img->ymin) / 500) * 10);
		img->ymin = img->ymin +(((img->ymax - img->ymin) / 500) * 10);
	}
}

void	qaws_press(int keycode, t_data*img)
{
	if (keycode == 113)
		img->fx += 0.01;
	else if (keycode == 97)
		img->fx -= 0.01;
	else if (keycode == 119)
		img->fy += 0.01;
	else if (keycode == 115)
		img->fy -= 0.01;
}

int	key_press(int keycode, t_data *img)
{
	if (keycode == 65307)
		close_window(img);
	else if ((keycode >= 111 && keycode <= 113) || keycode == 99
		|| keycode == 97 || keycode == 119 || keycode == 115
		|| (keycode >= 65361 && keycode <= 65364))
	{
		if (keycode == 111)
		{
			if (img->max_iter > 10)
				img->max_iter -= 10;
		}
		else if (keycode == 112)
			img->max_iter += 10;
		else if (keycode == 99)
			img->color += 1;
		qaws_press(keycode, img);
		arrow_press(keycode, img);
		draw_fractol(img);
	}
	return (EXIT_SUCCESS);
}
