/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:02:41 by abalasub          #+#    #+#             */
/*   Updated: 2024/03/01 17:03:35 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <math.h>

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*fractal;
	int		bpp;
	int		ll;
	int		endian;
	int		max_iter;
	int		zoom_direction;
	int		color;
	int		palette[5];
	double	zoom;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	fx;
	double	fy;
}			t_data;

int		burningship(int x, int y, t_data *img);
int		mandelbrot(int x, int y, t_data *img);
int		julia(int x, int y, t_data *img);
int		mouse_hook(int mousecode, int x, int y, t_data *img);
int		close_window(t_data *img);
int		key_press(int keycode, t_data *img);
int		sign(char *number);
int		init_julia(int argc, char **argv, t_data *img);
int		check_params(char *param);
int		check_fract(char *str);
void	pixel_put_img(t_data *data, int x, int y, int color);
void	draw_fractol(t_data *img);
void	zoom(double zoom_factor, int x, int y, t_data *img);
void	display_info(t_data *img);
void	print_keybind(void);
void	print_error(void);

double	ft_atod(char *number);
#endif
