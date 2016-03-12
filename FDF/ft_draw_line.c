/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 18:18:08 by pcalime           #+#    #+#             */
/*   Updated: 2016/03/12 15:50:51 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line_x(t_data data, t_point p1, t_point p2, float slope)
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

void	ft_draw_line_y(t_data data, t_point p1, t_point p2, float slope)
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

void	ft_draw_line(t_data data, t_point p1, t_point p2)
{
	float	slope;
	t_point swap;

	slope = (p2.y - p1.y) / (p2.x - p1.x);
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
