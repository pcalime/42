/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 14:36:39 by pcalime           #+#    #+#             */
/*   Updated: 2016/03/21 18:00:23 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>

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
}				t_data;

void			ft_julia();
int				ft_exit_win(int keycode, void *param);
int				ft_mouse_ride(int x, int y, void *param);
void			put_pixel_to_img(t_data *data, int x, int y, int color);

#endif
