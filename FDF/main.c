/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 17:17:56 by pcalime           #+#    #+#             */
/*   Updated: 2016/02/21 17:50:07 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	data.win = mlx_new_window(data.mlx, 300, 300, "test");
	ft_draw_line(data, p1, p2);
	mlx_loop(data.mlx);
}
