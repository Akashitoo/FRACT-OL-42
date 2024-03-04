/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:54:20 by abalasub          #+#    #+#             */
/*   Updated: 2024/03/01 17:03:18 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	init_img(t_data *img, char **argv)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, 500, 500, "fractol");
	img->fractal = argv[1];
	img->zoom = 1.0;
	img->xmin = -2;
	img->xmax = 2;
	img->ymin = -2;
	img->ymax = 2;
	img->color = 0;
	img->palette[0] = 0xff3366;
	img->palette[1] = 0x33ccff;
	img->palette[2] = 0x650f1e;
	img->palette[3] = 0xFFFFFF;
	img->palette[4] = 0x000000;
	img->max_iter = 100;
	img->zoom_direction = 1;
	img->img = mlx_new_image(img->mlx, 500, 500);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->ll, &img->endian);
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc < 2 || !check_fract(argv[1]) || init_julia(argc, argv, &img))
	{
		print_error();
		exit(0);
		return (0);
	}
	init_img(&img, argv);
	draw_fractol(&img);
	print_keybind();
	mlx_mouse_hook(img.win, mouse_hook, &img);
	mlx_key_hook(img.win, key_press, &img);
	mlx_hook(img.win, 17, 0, close_window, &img);
	mlx_loop(img.mlx);
	return (0);
}
