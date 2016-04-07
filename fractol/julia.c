/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:57:04 by pcalime           #+#    #+#             */
/*   Updated: 2016/04/06 22:12:23 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fract	ft_init_julia(void)
{
	t_fract	ret;

	ret.x1 = -1.5;
	ret.x2 = 1.5;
	ret.y1 = -1.2;
	ret.y2 = 1.2;
	ret.image_x = 800;
	ret.image_y = 800;
	ret.zoom_x = ret.image_x / (ret.x2 - ret.x1);
	ret.zoom_y = ret.image_y / (ret.y2 - ret.y1);
	ret.imax = 50;
	ret.c_r = 0;
	ret.c_i = 0;
	ret.z_r = 0;
	ret.z_i = 0;
	ret.tmp_r = 0.285;
	ret.tmp_i = 0.01;
	ret.i = 0;
	return (ret);
}

void		ft_julia_img(t_data *data, t_fract ft)
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
			ft.z_r = x / ft.zoom_x + ft.x1;
			ft.z_i = y / ft.zoom_y + ft.y1;
			ft.c_r = ft.tmp_r;
			ft.c_i = ft.tmp_i;
			ft.i = -1;
			while (ft.z_r * ft.z_r + ft.z_i * ft.z_i < 4 && ++ft.i < ft.imax)
			{
				tmp = ft.z_r;
				ft.z_r = ft.z_r * ft.z_r - ft.z_i * ft.z_i + ft.c_r;
				ft.z_i = 2 * ft.z_i * tmp + ft.c_i;
			}
			if (ft.i == ft.imax)
				put_pixel_to_img(data, x, y, 0xff0000);
			else
				put_pixel_to_img(data, x, y, ft.i * 255 / ft.imax);
		}
	}
}

void			ft_julia()
{
	t_data	*data;
	t_fract	fract;

	data = ft_memalloc(sizeof(t_data));
	data->fract = 1;
	fract = ft_init_julia();
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 800, 800, "julia");
	data->img = mlx_new_image(data->mlx, 800, 800);
	data->img_data = mlx_get_data_addr(data->img, &data->nbit, &data->line, &data->endian);
	data->deca_nbit = data->nbit >> 3;
	ft_julia_img(data, fract);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook(data->win, 6, 0, ft_mouse_ride, data);
	mlx_key_hook(data->win, ft_exit_win, 0);
	mlx_loop(data->mlx);
}
