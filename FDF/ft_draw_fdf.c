/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:26:03 by pcalime           #+#    #+#             */
/*   Updated: 2016/03/19 18:29:53 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_horizont(t_data data, int **tab, int tab_x_y[2], int ratio)
{
	int		cpt;
	int		cpt2;
	t_point	f_p;
	t_point	p1;
	t_point	p2;

	f_p = ft_first_pt(tab_x_y[0], tab_x_y[1], ratio);
	cpt = 0;
	cpt2 = 0;
	while (cpt2 < tab_x_y[1])
	{
		while (cpt < tab_x_y[0] - 1)
		{
			p1.x = f_p.x + ratio * cpt;
			p1.y = f_p.y - ratio * cpt - tab[cpt2][cpt] * ratio / 3;
			p2.x = f_p.x + ratio * (cpt + 1);
			p2.y = f_p.y - ratio * (cpt + 1) - tab[cpt2][cpt + 1] * ratio / 3;
			ft_draw_line(data, p1, p2);
			cpt++;
		}
		f_p.x += ratio;
		f_p.y += ratio;
		cpt2++;
		cpt = 0;
	}
}

static void	ft_draw_vertical(t_data data, int **tab, int tab_x_y[2], int ratio)
{
	int		cpt;
	int		cpt2;
	t_point	f_p;
	t_point	p1;
	t_point	p2;

	f_p = ft_first_pt(tab_x_y[0], tab_x_y[1], ratio);
	cpt = 0;
	cpt2 = 0;
	while (cpt < tab_x_y[0])
	{
		while (cpt2 < tab_x_y[1] - 1)
		{
			p1.x = f_p.x + ratio * cpt2;
			p1.y = f_p.y + ratio * cpt2 - tab[cpt2][cpt] * ratio / 3;
			p2.x = f_p.x + ratio * (cpt2 + 1);
			p2.y = f_p.y + ratio * (cpt2 + 1) - tab[cpt2 + 1][cpt] * ratio / 3;
			ft_draw_line(data, p1, p2);
			cpt2++;
		}
		f_p.x += ratio;
		f_p.y -= ratio;
		cpt++;
		cpt2 = 0;
	}
}

static int	ft_exit_win(int keycode, void *param)
{
	param = NULL;
	if (keycode == 53)
		exit(0);
	return (0);
}

void		ft_draw_fdf(int x, int y, int **tab)
{
	int		ratio;
	t_data	data;
	int		tab_x_y[2];

	tab_x_y[0] = x;
	tab_x_y[1] = y;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "fdf");
	ratio = ft_calculate_ratio(x, y, tab);
	ft_draw_vertical(data, tab, tab_x_y, ratio);
	ft_draw_horizont(data, tab, tab_x_y, ratio);
	mlx_key_hook(data.win, ft_exit_win, 0);
	mlx_loop(data.mlx);
}
