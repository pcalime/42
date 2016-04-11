/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 14:58:12 by pcalime           #+#    #+#             */
/*   Updated: 2016/04/06 22:05:48 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_fractol(char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		ft_mandelbrot();
	else if (ft_strcmp(str, "julia") == 0)
		ft_julia();
	else if (ft_strcmp(str, "burningship") == 0)
		ft_bns();
	else
	{
		ft_putstr("Error : Wrong fractal name.\n");
		return (0);
	}
	return (1);
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
	ft_putstr(", burningship .\n");
	return (0);
}
