/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 14:36:39 by pcalime           #+#    #+#             */
/*   Updated: 2016/03/22 15:12:47 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define SIZE_WIN 600
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>


typedef struct	s_fract
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zoom_x;
	double		zoom_y;
	double		image_x;
	double		image_y;
	double		imax;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp_r;
	double		tmp_i;
	int			i;
}				t_fract;



typedef struct	s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			nbit;
	int			deca_nbit;
	int			line;
	int			endian;
	int			fract;
	int			pause;
	int			color;
	t_fract	new_frt;
}				t_data;

void			ft_julia();
void			ft_mandelbrot();
int				ft_key_press(int keycode, void *param);
int				ft_mouse_ride(int x, int y, void *param);
void			put_pixel_to_img(t_data *data, int x, int y, t_fract ft);
void		ft_julia_img(t_data *data, t_fract ft);
t_fract	ft_init_julia(void);
t_fract	ft_init_mandelbrot(void);
void		ft_mandelbrot_img(t_data *data, t_fract ft);
void new_image(t_data *data, t_fract new_frt);

#endif
