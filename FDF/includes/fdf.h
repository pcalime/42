/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 17:10:20 by pcalime           #+#    #+#             */
/*   Updated: 2016/03/15 18:07:27 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

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
char	*ft_read(char *str);
int		ft_count_x(char *str);
int		ft_count_y(char *str);
void	ft_fill_tab(int **tab, char *str, int x, int y);
int		ft_calculate_ratio(int x, int y, int **tab);
t_point	ft_first_pt(int x, int y, int ratio);
void	ft_draw_fdf(int x, int y, int **tab);

#endif
