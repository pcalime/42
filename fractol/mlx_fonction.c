/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 17:39:09 by pcalime           #+#    #+#             */
/*   Updated: 2016/03/21 20:59:19 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_exit_win(int keycode, void *param)
{
	param = NULL;
	if (keycode == 53)
		exit(0);
	return (0);
}

int		ft_mouse_ride(int x, int y, void *param)
{
	param = NULL;
	x = 12;
	y = 4;
	//	if (x <= 1920 && x >= 0 && y <= 1080 && y >= 0)
	//		printf("x = %d ; y = %d\n", x, y);
	return (0);
}

int	convert_bit_to_char(char *str)
{
	int	ret;

	ret = 0;
	ret += (str[0] - 48) * 128;
	ret += (str[1] - 48) * 64;
	ret += (str[2] - 48) * 32;
	ret += (str[3] - 48) * 16;
	ret += (str[4] - 48) * 8;
	ret += (str[5] - 48) * 4;
	ret += (str[6] - 48) * 2;
	ret += (str[7] - 48);
	return (ret);
}

void	put_pixel_to_img(t_data *data, int x, int y, int color)
{
	char	*color_bit;
	int		color_red;
	int		color_green;
	int		color_blue;

	color_bit = convert_int_to_bit(color);
	printf("color_bit = %s ; ", color_bit);
	color_red = convert_bit_to_char(&color_bit[8]);
	color_green = convert_bit_to_char(&color_bit[16]);
	color_blue = convert_bit_to_char(&color_bit[24]);
	printf("color = %d , red = %d , green = %d , blue = %d\n", color, color_red, color_green, color_blue);
	data->img_data[x * data->deca_nbit + (y * data->line)] = (char)color_blue;
	data->img_data[x * data->deca_nbit + (y * data->line) + 1] = (char)color_green;
	data->img_data[x * data->deca_nbit + (y * data->line) + 2] = (char)color_red;
}
