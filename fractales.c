/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:05:15 by abalasub          #+#    #+#             */
/*   Updated: 2024/03/01 15:08:03 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	burningship(int x, int y, t_data *img)
{
	double	jx;
	double	jy;
	double	tx;
	double	ty;
	int		i;

	jx = img->xmin + ((double)x / 500) * (img->xmax - img->xmin);
	jy = img->ymin + ((double)y / 500) * (img->ymax - img->ymin);
	i = 0;
	while (jx * jx + jy * jy < 4.0 && i < img->max_iter)
	{
		jx = fabs(jx);
		jy = fabs(jy);
		tx = jx;
		ty = jy;
		jx = tx * tx - ty * ty
			+ (img->xmin + ((double)x / 500) * (img->xmax - img->xmin));
		jy = 2 * tx * ty
			+ (img->ymin + ((double)y / 500) * (img->ymax - img->ymin));
		i++;
	}
	if (i == img->max_iter)
		return (0x000000);
	else
		return (img->palette[img->color % 4] + (0x110011) * i);
}

int	mandelbrot(int x, int y, t_data *img)
{
	double	jx;
	double	jy;
	double	tx;
	double	ty;
	int		i;

	jx = img->xmin + ((double)x / 500) * (img->xmax - img->xmin);
	jy = img->ymin + ((double)y / 500) * (img->ymax - img->ymin);
	i = 0;
	while (jx * jx + jy * jy < 4.0 && i < img->max_iter)
	{
		tx = jx;
		ty = jy;
		jx = tx * tx - ty * ty
			+ (img->xmin + ((double)x / 500) * (img->xmax - img->xmin));
		jy = 2 * tx * ty
			+ (img->ymin + ((double)y / 500) * (img->ymax - img->ymin));
		i++;
	}
	if (i == img->max_iter)
		return (0x000000);
	else
		return (img->palette[img->color % 4] + (0x110011) * i);
}

int	julia(int x, int y, t_data *img)
{
	double	jx;
	double	jy;
	double	tx;
	double	ty;
	int		i;

	jx = img->xmin + ((double)x / 500) * (img->xmax - img->xmin);
	jy = img->ymin + ((double)y / 500) * (img->ymax - img->ymin);
	i = 0;
	while (jx * jx + jy * jy < 4.0 && i < img->max_iter)
	{
		tx = jx;
		ty = jy;
		jx = tx * tx - ty * ty + img->fx;
		jy = 2 * tx * ty + img->fy;
		i++;
	}
	if (i == img->max_iter)
		return (0);
	else
		return (img->palette[img->color % 4] - (0x110011) * i);
}
