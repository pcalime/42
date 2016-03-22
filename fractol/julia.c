/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:57:04 by pcalime           #+#    #+#             */
/*   Updated: 2016/03/22 15:17:51 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fract	ft_init_julia(void)
{
	t_fract	ret;
	ret.x1 = -1;
	ret.x2 = 1;
	ret.y1 = -1.2;
	ret.y2 = 1.2;
	ret.image_x = 1080;
	ret.image_y = 1080;
	ret.zoom_x = ret.image_x / (ret.x2 - ret.x1);
	ret.zoom_y = ret.image_y / (ret.y2 - ret.y1);
	ret.imax = 30;
	ret.c_r = 0;
	ret.c_i = 0;
	ret.z_r = 0;
	ret.z_i = 0;
	ret.tmp_r = 0.285;
	ret.tmp_i = 0.01;
	ret.i = 0;
	return (ret);
}

static void		ft_julia_img(t_data *data, t_fract ft)
{
	double	x;
	double	y;
	double	tmp;

	x = 0;
	while (x < ft.image_x)
	{
		y = 0;
		while (y < ft.image_y)
		{
			ft.z_r = x / ft.zoom_x + ft.x1;
			ft.z_i = y / ft.zoom_y + ft.y1;
			ft.c_r = ft.tmp_r;
			ft.c_i = ft.tmp_i;
			ft.i = 0;
			while (ft.z_r * ft.z_r + ft.z_i * ft.z_i < 4 && ft.i < ft.imax)
			{
				tmp = ft.z_r;
				ft.z_r = ft.z_r * ft.z_r - ft.z_i * ft.z_i + ft.c_r;
				ft.z_i = 2 * ft.z_i * tmp + ft.c_i;
				ft.i++;
			}
			if (ft.i == ft.imax)
				put_pixel_to_img(data, x, y, 0xff0000);
			else
				put_pixel_to_img(data, x, y, ft.i * 255 / ft.imax);
			y++;
		}
		x++;
	}
}

void			ft_julia()
{
	t_data	data;
	t_fract	fract;

	fract = ft_init_julia();
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "julia");
	data.img = mlx_new_image(data.mlx, 1920, 1080);
	data.img_data = mlx_get_data_addr(data.img, &data.nbit, &data.line, &data.endian);
	data.deca_nbit = data.nbit >> 3;

	ft_julia_img(&data, fract);


	mlx_put_image_to_window(data.mlx, data.win, data.img, 1, 1);
	mlx_hook(data.win, 6, 0, ft_mouse_ride, 0);
	mlx_key_hook(data.win, ft_exit_win, 0);
	mlx_loop(data.mlx);
}
