/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 17:17:56 by pcalime           #+#    #+#             */
/*   Updated: 2016/03/15 13:53:15 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>


int		ft_exit_win(int keycode, void *param)
{
	param = NULL;
	if (keycode == 53)
		exit(0);
	return (0);
}


int		main()
{
	t_data	data;
	t_point	p1;
	t_point	p2;
	t_point	p3;
	t_point	p4;

	p1.x = 500;
	p1.y = 800;
	p2.x = 700;
	p2.y = 600;
	p3.x = 300;
	p3.y = 1000;
	p4.x = 100;
	p4.y = 1080;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "test");
	ft_draw_line(data, p1, p2);
	ft_draw_line(data, p2, p3);
	ft_draw_line(data, p1, p3);
	ft_draw_line(data, p1, p4);
	ft_draw_line(data, p3, p4);
	ft_draw_line(data, p3, p1);
	ft_draw_line(data, p3, p4);
	ft_draw_line(data, p3, p4);
	ft_draw_line(data, p3, p4);
	ft_draw_line(data, p3, p4);
	ft_draw_line(data, p3, p4);
	ft_draw_line(data, p3, p4);
	ft_draw_line(data, p3, p4);
	ft_draw_line(data, p3, p4);
	ft_draw_line(data, p3, p4);
	mlx_key_hook(data.win, ft_exit_win, 0);
	mlx_loop(data.mlx);
	return (0);
}
