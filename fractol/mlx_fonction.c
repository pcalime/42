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

int		ft_key_press(int keycode, void *param)
{
	t_data *data;

	data = param;
	if (keycode == 53)
		exit(0);
	if (keycode == 49)
		data->pause = data->pause == 0 ? 1 : 0;
		printf("data pause = %d\n", data->pause);
	if (keycode <= 92 && keycode >= 82)
	{
		data->color = keycode - 82;
		printf("%d", data->color);
		new_image(data, data->new_frt);
	}
	return (0);
}

void new_image(t_data *data, t_fract new_frt)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, SIZE_WIN, SIZE_WIN);
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
	if (data->pause == 0)
	{
		if (data->fract == 1)
			new_frt = ft_init_julia();
		else if (data->fract == 2)
			new_frt = ft_init_mandelbrot();
		else if (data->fract == 3)
			data->fract = 3;
		new_frt.tmp_r = (double)(x - (SIZE_WIN / 2)) / (SIZE_WIN / 2);
		new_frt.tmp_i = (double)(y - (SIZE_WIN / 2)) / (SIZE_WIN / 2);
		new_image(data, new_frt);
		data->new_frt = new_frt;
		data->color++;
		if(data->color == 8)
			data->color++;
		else if(data->color == 10)
			data->color = 0;
		printf("x = %d ; y = %d\n", x, y);
	}
	return (0);
}

void	put_pixel_to_img(t_data *data, int x, int y, t_fract ft)
{
	data->img_data[x * data->deca_nbit + (y * data->line)] = 0;
	data->img_data[x * data->deca_nbit + (y * data->line) + 1] = 0;
	data->img_data[x * data->deca_nbit + (y * data->line) + 2] = 0;
	if (data->color == 0)
	{
		if (ft.i == ft.imax)
			data->img_data[x * data->deca_nbit + (y * data->line)] = 255;
		else
			data->img_data[x * data->deca_nbit + (y * data->line)] = ft.i * 255 / ft.imax;
	}
	else if (data->color == 1)
	{
		if (ft.i == ft.imax)
			data->img_data[x * data->deca_nbit + (y * data->line)] = 255;
		else
			data->img_data[x * data->deca_nbit + (y * data->line) + 1] = ft.i * 255 / ft.imax;
	}
	else if (data->color == 2)
	{
		if (ft.i == ft.imax)
			data->img_data[x * data->deca_nbit + (y * data->line)] = 255;
		else
			data->img_data[x * data->deca_nbit + (y * data->line) + 2] = ft.i * 255 / ft.imax;
	}
	else if (data->color == 3)
	{
		if (ft.i == ft.imax)
			data->img_data[x * data->deca_nbit + (y * data->line) + 1] = 255;
		else
			data->img_data[x * data->deca_nbit + (y * data->line)] = ft.i * 255 / ft.imax;
	}
	else if (data->color == 4)
	{
		if (ft.i == ft.imax)
			data->img_data[x * data->deca_nbit + (y * data->line) + 1] = 255;
		else
			data->img_data[x * data->deca_nbit + (y * data->line) + 1] = ft.i * 255 / ft.imax;
	}
	else if (data->color == 5)
	{
		if (ft.i == ft.imax)
			data->img_data[x * data->deca_nbit + (y * data->line) + 1] = 255;
		else
			data->img_data[x * data->deca_nbit + (y * data->line) + 2] = ft.i * 255 / ft.imax;
	}
	else if (data->color == 6)
	{
		if (ft.i == ft.imax)
			data->img_data[x * data->deca_nbit + (y * data->line) + 2] = 255;
		else
			data->img_data[x * data->deca_nbit + (y * data->line)] = ft.i * 255 / ft.imax;
	}
	else if (data->color == 7)
	{
		if (ft.i == ft.imax)
			data->img_data[x * data->deca_nbit + (y * data->line) + 2] = 255;
		else
			data->img_data[x * data->deca_nbit + (y * data->line) + 1] = ft.i * 255 / ft.imax;
	}
	else if (data->color == 9)
	{
		if (ft.i == ft.imax)
			data->img_data[x * data->deca_nbit + (y * data->line) + 2] = 255;
		else
			data->img_data[x * data->deca_nbit + (y * data->line) + 2] = ft.i * 255 / ft.imax;
	}
	else if (data->color == 10)
	{
		if (ft.i == ft.imax)
		{
			data->img_data[x * data->deca_nbit + (y * data->line)] = 60;
			data->img_data[x * data->deca_nbit + (y * data->line) + 1] = 65;
			data->img_data[x * data->deca_nbit + (y * data->line) + 2] = 50;
		}
		else
		{
			data->img_data[x * data->deca_nbit + (y * data->line)] = 52;
			data->img_data[x * data->deca_nbit + (y * data->line) + 1] = 50;
			data->img_data[x * data->deca_nbit + (y * data->line) + 2] = ft.i * 255 / ft.imax;
		}
	}
	/*
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
		(char)color_red;*/
}
