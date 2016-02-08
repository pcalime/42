/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 18:18:08 by pcalime           #+#    #+#             */
/*   Updated: 2016/02/08 19:26:37 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef	struct
{
	void	*mlx;
	void	*win;
} data_t;

typedef	struct
{
	float	x;
	float	y;
} point_t;


void	ft_draw_line_x(data_t data, point_t p1, point_t p2, float slope)
{
	float	x;
	float	y;

	y = p1.y;
	while (y <= p2.y)
	{
		x = (y - p1.y) / slope + p1.x;
		x += 0.5;
		mlx_pixel_put(data.mlx, data.win, (int)x, (int)y, 0xffffff);
		y++;
	}
}

void	ft_draw_line_y(data_t data, point_t p1, point_t p2, float slope)
{
	float	x;
	float	y;

	x = p1.x;
	while (x <= p2.x)
	{
		y = slope * (x - p1.x) + p1.y;
		y += 0.5;
		mlx_pixel_put(data.mlx, data.win, (int)x, (int)y, 0xffffff);
		x++;
	}
}

void	ft_draw_line(data_t data, point_t p1, point_t p2)
{
	float	slope;
	point_t swap;

	slope = (p2.y - p1.y)/(p2.x - p1.x);
	if (slope < 1 && slope > -1)
	{
		if (p1.x >= p2.x)
		{
			swap = p1;
			p1 = p2;
			p2 = swap;
		}
		ft_draw_line_y(data, p1, p2, slope);
	}
	else
	{
		if (p1.y >= p2.y)
		{
			swap = p1;
			p1 = p2;
			p2 = swap;
		}
		ft_draw_line_x(data, p1, p2, slope);
	}
}

int		main(void)
{
	data_t	data;
	point_t p1;
	point_t p2;

	p1.x = 200;
	p1.y = 100;
	p2.x = 200;
	p2.y = 200;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 300, 300, "test");
	mlx_pixel_put(data.mlx, data.win, 150, 150, 0xffffff);
	ft_draw_line(data, p1, p2);
	mlx_loop(data.mlx);
}
