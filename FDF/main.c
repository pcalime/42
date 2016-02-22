/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 17:17:56 by pcalime           #+#    #+#             */
/*   Updated: 2016/02/22 19:15:14 by pcalime          ###   ########.fr       */
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


int		main(int argc, char **argv)
{
	if (argc != 5)
		return (1);
	t_data	data;
	t_point	p1;
	t_point	p2;

	p1.x = (float)ft_atoi(argv[1]);
	p1.y = (float)ft_atoi(argv[2]);
	p2.x = (float)ft_atoi(argv[3]);
	p2.y = (float)ft_atoi(argv[4]);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "test");
	ft_draw_line(data, p1, p2);
	mlx_key_hook(data.win, ft_exit_win, 0);
	mlx_loop(data.mlx);
	return (0);
}
