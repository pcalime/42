/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_to_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 03:38:14 by pcalime           #+#    #+#             */
/*   Updated: 2016/04/09 04:14:06 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	color1(t_data *data, int x, int y, t_fract ft)
{
	if (data->color == 0)
	{
		if (ft.i == ft.imax)
			data->img_data[x * data->deca_nbit + (y * data->line)] = 255;
		else
			data->img_data[x * data->deca_nbit + (y * data->line)] =
				ft.i * 255 / ft.imax;
	}
	else if (data->color == 1)
	{
		if (ft.i == ft.imax)
			data->img_data[x * data->deca_nbit + (y * data->line)] = 255;
		else
			data->img_data[x * data->deca_nbit + (y * data->line) + 1] =
				ft.i * 255 / ft.imax;
	}
	else if (data->color == 2)
	{
		if (ft.i == ft.imax)
			data->img_data[x * data->deca_nbit + (y * data->line)] = 255;
		else
			data->img_data[x * data->deca_nbit + (y * data->line) + 2] =
				ft.i * 255 / ft.imax;
	}
}

static void	color2(t_data *data, int x, int y, t_fract ft)
{
	if (data->color == 3)
	{
		if (ft.i == ft.imax)
			data->img_data[x * data->deca_nbit + (y * data->line) + 1] = 255;
		else
			data->img_data[x * data->deca_nbit + (y * data->line)] =
				ft.i * 255 / ft.imax;
	}
	else if (data->color == 4)
	{
		if (ft.i == ft.imax)
			data->img_data[x * data->deca_nbit + (y * data->line) + 1] = 255;
		else
			data->img_data[x * data->deca_nbit + (y * data->line) + 1] =
				ft.i * 255 / ft.imax;
	}
	else if (data->color == 5)
	{
		if (ft.i == ft.imax)
			data->img_data[x * data->deca_nbit + (y * data->line) + 1] = 255;
		else
			data->img_data[x * data->deca_nbit + (y * data->line) + 2] =
				ft.i * 255 / ft.imax;
	}
}

static void	color3(t_data *data, int x, int y, t_fract ft)
{
	if (data->color == 6)
	{
		if (ft.i == ft.imax)
			data->img_data[x * data->deca_nbit + (y * data->line) + 2] = 255;
		else
			data->img_data[x * data->deca_nbit + (y * data->line)] =
				ft.i * 255 / ft.imax;
	}
	else if (data->color == 7)
	{
		if (ft.i == ft.imax)
			data->img_data[x * data->deca_nbit + (y * data->line) + 2] = 255;
		else
			data->img_data[x * data->deca_nbit + (y * data->line) + 1] =
				ft.i * 255 / ft.imax;
	}
	else if (data->color == 9)
	{
		if (ft.i == ft.imax)
			data->img_data[x * data->deca_nbit + (y * data->line) + 2] = 255;
		else
			data->img_data[x * data->deca_nbit + (y * data->line) + 2] =
				ft.i * 255 / ft.imax;
	}
}

void		put_pixel_to_img(t_data *data, int x, int y, t_fract ft)
{
	data->img_data[x * data->deca_nbit + (y * data->line)] = 0;
	data->img_data[x * data->deca_nbit + (y * data->line) + 1] = 0;
	data->img_data[x * data->deca_nbit + (y * data->line) + 2] = 0;
	color1(data, x, y, ft);
	if (data->img_data[x * data->deca_nbit + (y * data->line)] == 0)
		color2(data, x, y, ft);
	if (data->img_data[x * data->deca_nbit + (y * data->line) + 1] == 0)
		color3(data, x, y, ft);
	if (data->color == 10)
	{
		if (ft.i == ft.imax)
		{
			data->img_data[x * data->deca_nbit + (y * data->line)] = 168;
			data->img_data[x * data->deca_nbit + (y * data->line) + 1] = 185;
			data->img_data[x * data->deca_nbit + (y * data->line) + 2] = 2;
		}
		else
		{
			data->img_data[x * data->deca_nbit + (y * data->line)] = 255;
			data->img_data[x * data->deca_nbit + (y * data->line) + 1] = 127;
			data->img_data[x * data->deca_nbit + (y * data->line) + 2] =
				ft.i * 255 / ft.imax;
		}
	}
}
