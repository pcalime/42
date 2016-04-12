/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 01:19:34 by pcalime           #+#    #+#             */
/*   Updated: 2016/04/12 01:19:38 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_red(t_data *data)
{
	int		ret;
	int		check;

	check = -5;
	if (data->fract == 3)
		check = -6;
	ret = 0;
	if (data->img_data[0 * data->deca_nbit + (0 * data->line)] == check)
		ret++;
	if (data->img_data[1 * data->deca_nbit + (1 * data->line)] == check)
		ret++;
	if (data->img_data[2 * data->deca_nbit + (2 * data->line)] == check)
		ret++;
	if (data->img_data[3 * data->deca_nbit + (3 * data->line)] == check)
		ret++;
	if (data->img_data[4 * data->deca_nbit + (4 * data->line)] == check)
		ret++;
	return (ret);
}

static int	check_green(t_data *data)
{
	int		ret;
	int		check;

	check = -5;
	if (data->fract == 3)
		check = -6;
	ret = 0;
	if (data->img_data[0 * data->deca_nbit + (0 * data->line) + 1] == check)
		ret++;
	if (data->img_data[1 * data->deca_nbit + (1 * data->line) + 1] == check)
		ret++;
	if (data->img_data[2 * data->deca_nbit + (2 * data->line) + 1] == check)
		ret++;
	if (data->img_data[3 * data->deca_nbit + (3 * data->line) + 1] == check)
		ret++;
	if (data->img_data[4 * data->deca_nbit + (4 * data->line) + 1] == check)
		ret++;
	return (ret);
}

static int	check_blue(t_data *data)
{
	int		ret;
	int		check;

	check = -5;
	if (data->fract == 3)
		check = -6;
	ret = 0;
	if (data->img_data[0 * data->deca_nbit + (0 * data->line) + 2] == check)
		ret++;
	if (data->img_data[1 * data->deca_nbit + (1 * data->line) + 2] == check)
		ret++;
	if (data->img_data[2 * data->deca_nbit + (2 * data->line) + 2] == check)
		ret++;
	if (data->img_data[3 * data->deca_nbit + (3 * data->line) + 2] == check)
		ret++;
	if (data->img_data[4 * data->deca_nbit + (4 * data->line) + 2] == check)
		ret++;
	return (ret);
}

void		check_bug(t_data *data)
{
	int		x;
	int		y;

	x = check_blue(data) + check_green(data) + check_red(data);
	if (x != 5)
		return ;
	x = -1;
	while (++x < data->new_frt.image_x)
	{
		y = -1;
		while (++y < data->new_frt.image_y)
		{
			data->img_data[x * data->deca_nbit + (y * data->line)] = 0;
			data->img_data[x * data->deca_nbit + (y * data->line) + 1] = 0;
			data->img_data[x * data->deca_nbit + (y * data->line) + 2] = 0;
		}
	}
}
