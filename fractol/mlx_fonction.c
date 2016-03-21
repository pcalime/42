/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 17:39:09 by pcalime           #+#    #+#             */
/*   Updated: 2016/03/21 18:39:30 by pcalime          ###   ########.fr       */
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

static char	*convert_int_to_bit(int nbr)
{
	int		cmpt;
	int		cmpt2;
	char	*ret;

	ret = (char *)ft_memalloc(sizeof(char) * 25);
	if (nbr < 0)
		return (ft_strdup("0"));
	cmpt = 2147483648;
	cmpt2 = 1;
	ret[0] = '0';
	while (cmpt > 0)
	{
		ret[cmpt] = nbr % cmpt + 48;
		cmpt /= 2;
		cmpt2++;
	}
}

void	put_pixel_to_img(t_data *data, int x, int y, int color)
{
	char	*color_bit;
	int		color_red;
	int		color_green;
	int		color_blue;
	color_bit = convert_int_to_bit(color);
	printf("color_bit = %s", color_bit);
	color_red = (color - 256 * 256) % (256 * 256 * 256);
	color_green = (color - 256) % (256 * 256);
	color_blue = color % 256;
	printf("color = %d , red = %d , green = %d , blue = %d\n", color, color_red, color_green, color_blue);
	data->img_data[x * data->deca_nbit + (y * data->line)] = (char)color_red;
	data->img_data[x * data->deca_nbit + (y * data->line) + 1] = (char)color_green;
	data->img_data[x * data->deca_nbit + (y * data->line) + 2] = (char)color_blue;
}
