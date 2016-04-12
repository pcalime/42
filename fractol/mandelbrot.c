/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:03:24 by pcalime           #+#    #+#             */
/*   Updated: 2016/04/11 23:19:35 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fract		ft_init_mandelbrot(void)
{
	t_fract	ret;

	ret.x1 = -2.1;
	ret.x2 = 0.6;
	ret.y1 = -1.2;
	ret.y2 = 1.2;
	ret.image_x = SIZE_WIN;
	ret.image_y = SIZE_WIN;
	ret.zoom_x = ret.image_x / (ret.x2 - ret.x1);
	ret.zoom_y = ret.image_y / (ret.y2 - ret.y1);
	ret.imax = 50;
	ret.c_r = 0;
	ret.c_i = 0;
	ret.z_r = 0;
	ret.z_i = 0;
	ret.tmp_r = 0;
	ret.tmp_i = 0;
	ret.i = 0;
	return (ret);
}

void		ft_mandelbrot_img(t_data *data, t_fract ft)
{
	double	x;
	double	y;
	double	tmp;

	x = -1;
	while (++x < ft.image_x)
	{
		y = -1;
		while (++y < ft.image_y)
		{
			ft.c_r = x / ft.zoom_x + ft.x1;
			ft.c_i = y / ft.zoom_y + ft.y1;
			ft.z_r = ft.tmp_r;
			ft.z_i = ft.tmp_i;
			ft.i = -1;
			while (ft.z_r * ft.z_r + ft.z_i * ft.z_i < 4 && ++ft.i < ft.imax)
			{
				tmp = ft.z_r;
				ft.z_r = ft.z_r * ft.z_r - ft.z_i * ft.z_i + ft.c_r;
				ft.z_i = 2 * ft.z_i * tmp + ft.c_i;
			}
			put_pixel_to_img(data, x, y, ft);
		}
	}
}

void		ft_mandelbrot(void)
{
	t_data	*data;
	t_fract	fract;

	data = ft_memalloc(sizeof(t_data));
	data->fract = 2;
	data->pause = 0;
	data->color = 0;
	data->new_frt = ft_init_mandelbrot();
	fract = ft_init_mandelbrot();
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SIZE_WIN, SIZE_WIN, "mandelbrot");
	data->img = mlx_new_image(data->mlx, SIZE_WIN, SIZE_WIN);
	data->img_data = mlx_get_data_addr(data->img, &data->nbit, &data->line,
			&data->endian);
	data->deca_nbit = data->nbit >> 3;
	ft_mandelbrot_img(data, fract);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 1, 1);
	mlx_hook(data->win, 6, 0, ft_mouse_ride, data);
	mlx_hook(data->win, 4, 0, ft_mouse_scroll, data);
	mlx_key_hook(data->win, ft_key_press, data);
	mlx_loop(data->mlx);
}
