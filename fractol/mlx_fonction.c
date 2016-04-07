/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 17:39:09 by pcalime           #+#    #+#             */
/*   Updated: 2016/04/06 22:06:16 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_exit_win(int keycode, void *param)
{
	param = NULL;
	if (keycode == 53)
		exit(0);
	return (0);
}

void new_image(t_data *data, t_fract new_frt)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, 800, 800);
	data->img_data = mlx_get_data_addr(data->img, &data->nbit, &data->line, &data->endian);
	if (data->fract == 1)
		ft_julia_img(data, new_frt);
	else if (data->fract == 2)
		ft_mandelbrot_img(data, new_frt);
	else if (data->fract == 3)
		data->fract = 3;
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
int		ft_mouse_ride(int x, int y, void *param)
{
	t_data *data;
	t_fract new_frt;

	data = param;
	if (data->fract == 1)
		new_frt = ft_init_julia();
	else if (data->fract == 2)
		new_frt = ft_init_mandelbrot();
	else if (data->fract == 3)
		data->fract = 3;
	new_frt.tmp_r = (double)(x - 500) / 500;
	new_frt.tmp_i = (double)(y - 500) / 500;
	new_image(data, new_frt);
	printf("x = %d ; y = %d\n", x, y);
	return (0);
}

void	put_pixel_to_img(t_data *data, int x, int y, int color)
{
	char	*color_bit;
	int		color_red;
	int		color_green;
	int		color_blue;

	color_bit = convert_int_to_bit(color);
	color_red = convert_bit_to_char(&color_bit[8]);
	color_green = convert_bit_to_char(&color_bit[16]);
	color_blue = convert_bit_to_char(&color_bit[24]);
	data->img_data[x * data->deca_nbit + (y * data->line)] = (char)color_blue;
	data->img_data[x * data->deca_nbit + (y * data->line) + 1] =
		(char)color_green;
	data->img_data[x * data->deca_nbit + (y * data->line) + 2] =
		(char)color_red;
}
