/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 17:10:20 by pcalime           #+#    #+#             */
/*   Updated: 2016/02/21 17:49:32 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft/libft.h"

typedef struct	s_data
{
	void		*mlx;
	void		*win;
}				t_data;

typedef struct	s_point
{
	float		x;
	float		y;
}				t_point;

void	ft_draw_line(t_data data, t_point p1, t_point p2);

#endif
