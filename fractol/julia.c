/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:57:04 by pcalime           #+#    #+#             */
/*   Updated: 2016/03/21 20:59:22 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



void	ft_julia()
{
	t_data	data;
	
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "julia");
	data.img = mlx_new_image(data.mlx, 1920, 1080);
	data.img_data = mlx_get_data_addr(data.img, &data.nbit, &data.line, &data.endian);
	data.deca_nbit = data.nbit >> 3;
	put_pixel_to_img(&data, 1, 1, 0xFF358B);
	put_pixel_to_img(&data, 2, 1, 0xFF358B);
	put_pixel_to_img(&data, 3, 1, 0xFF358B);
	put_pixel_to_img(&data, 4, 1, 0xFF358B);
	put_pixel_to_img(&data, 5, 1, 0xFF358B);
	put_pixel_to_img(&data, 6, 1, 0xFF358B);
	put_pixel_to_img(&data, 7, 1, 0xFF358B);
	put_pixel_to_img(&data, 8, 1, 0xFF358B);
	put_pixel_to_img(&data, 9, 1, 0xFF358B);
	put_pixel_to_img(&data, 10, 1, 0xFF358B);
	put_pixel_to_img(&data, 11, 1, 0xFF358B);
	put_pixel_to_img(&data, 12, 1, 0xFF358B);

	mlx_put_image_to_window(data.mlx, data.win, data.img, 1, 1);
	mlx_hook(data.win, 6, 0, ft_mouse_ride, 0);
	mlx_key_hook(data.win, ft_exit_win, 0);
	mlx_loop(data.mlx);
}
