/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 17:39:09 by pcalime           #+#    #+#             */
/*   Updated: 2016/04/09 03:55:59 by pcalime          ###   ########.fr       */
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

void	new_image(t_data *data, t_fract new_frt)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, SIZE_WIN, SIZE_WIN);
	data->img_data = mlx_get_data_addr(data->img, &data->nbit, &data->line,
			&data->endian);
	if (data->fract == 1)
		ft_julia_img(data, new_frt);
	else if (data->fract == 2)
		ft_mandelbrot_img(data, new_frt);
	else if (data->fract == 3)
		ft_bns_img(data, new_frt);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int		ft_mouse_ride(int x, int y, void *param)
{
	t_data	*data;

	data = param;
	if (data->pause == 0)
	{
		data->new_frt.tmp_r = (double)(x - (SIZE_WIN / 2)) / (SIZE_WIN / 2);
		data->new_frt.tmp_i = (double)(y - (SIZE_WIN / 2)) / (SIZE_WIN / 2);
		new_image(data, data->new_frt);
		if (data->color <= 8)
			data->color++;
		if (data->color == 8)
			data->color++;
		else if (data->color == 9)
			data->color = 0;
		printf("x = %d ; y = %d\n", x, y);
	}
	return (0);
}

static void ft_zoom(int keycode, t_data *data)
{
	if (keycode == 4)
	{
		data->new_frt.zoom_x *= 2;
		data->new_frt.zoom_y *= 2;
		data->new_frt.imax += 10;
	}
	if (keycode == 5)
	{
		data->new_frt.zoom_x /= 2;
		data->new_frt.zoom_y /= 2;
		data->new_frt.imax -= 10;
	}
}

int		ft_mouse_scroll(int keycode, int x, int y, void *param)
{
	t_data	*data;
	double	z_x;
	double	z_y;

	data = param;
	if (data->pause == 0)
		return (1);
	z_x = data->new_frt.zoom_x;
	z_y = data->new_frt.zoom_y;
	ft_zoom(keycode, data);
	data->new_frt.x1 += x / z_x - (x / data->new_frt.zoom_x);
	data->new_frt.y1 += y / z_y - (y / data->new_frt.zoom_y);
	new_image(data, data->new_frt);
	return (0);
}
