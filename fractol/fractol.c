/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 14:58:12 by pcalime           #+#    #+#             */
/*   Updated: 2016/03/22 13:16:46 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
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
	if (x <= 1920 && x >= 0 && y <= 1080 && y >= 0)
	{
		printf("x = %d ; y = %d\n", x, y);
	}
	return (0);
}	
*/
void	ft_mandelbrot()
{
	ft_putstr("1");
}

/*

void	ft_julia()
{
	t_data	data;
	float	x = 0;
	float	y = 0;
	float	x1 = -2.1;
	float	x2 = 0.6;
	float	y1 = -1.2;
	float	y2 = 1.2;
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	float	i;
	float	tmp;
	float	zoom = 450;
	float	iteration_max = 50;
	float	image_x = (x2 - x1) * zoom;
	float	image_y = (y2 - y1) * zoom;
	int		color;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "julia");
	while (x < image_x)
	{
		while (y < image_y)
		{
			c_r = x / zoom + x1;
			c_i = y / zoom + y1;
			z_r = 0.2;
			z_i = 0.2;
			i = 0;
			color = 0;
			while ((z_r * z_r + z_i * z_i < 2) && i < iteration_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i == iteration_max)
				mlx_pixel_put(data.mlx, data.win, (int)x, (int)y, color);
			else
				mlx_pixel_put(data.mlx, data.win, x, y, i * 255 / iteration_max);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_hook(data.win, 6, 0, ft_mouse_ride, 0);
	mlx_key_hook(data.win, ft_exit_win, 0);
	mlx_loop(data.mlx);
}
*/
void	ft_fractale3()
{
	ft_putstr("3");
}

int		ft_fractol(char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		ft_mandelbrot();
	else if (ft_strcmp(str, "julia") == 0)
		ft_julia();
	else if (ft_strcmp(str, "fractale3") == 0)
		ft_fractale3();
	else
	{
		ft_putstr("Error : Wrong fractal name.\n");
		return (0);
	}
	return(1);

}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_fractol(argv[1]) == 1)
			return (0);
	}
	else if (argc == 1)
		ft_putstr("Error : Too few arguments.\n");
	else
		ft_putstr("Error : Too much arguments.\n");
	ft_putstr("Please select a fractal between those : mandelbrot , julia ");
	ft_putstr(", fractale3 .\n");
	return (0);
}
