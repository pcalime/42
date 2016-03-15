/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:26:03 by pcalime           #+#    #+#             */
/*   Updated: 2016/03/15 17:26:24 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void ft_draw_horizontal(t_data data, int **tab, int tab_x_y[2], int ratio)
{
  int   cmpt;
  int   cmpt2;
  t_point first_point;
  t_point p1;
  t_point p2;

  first_point = ft_first_pt(tab_x_y[0], tab_x_y[1], ratio);
  cmpt = 0;
  cmpt2 = 0;
  while (cmpt2 < tab_x_y[1]) // traits horizontaux
	{
		while (cmpt < tab_x_y[0] - 1)
		{
			p1.x = first_point.x + ratio * cmpt;
			p1.y = first_point.y - ratio * cmpt - tab[cmpt2][cmpt] * ratio;
			p2.x = first_point.x + ratio * (cmpt + 1);
			p2.y = first_point.y - ratio * (cmpt + 1)- tab[cmpt2][cmpt + 1] * ratio;
			ft_draw_line(data, p1, p2);
			cmpt++;
		}
		first_point.x += ratio;
		first_point.y += ratio;
		cmpt2++;
		cmpt = 0;
	}
}

static void ft_draw_vertical(t_data data, int **tab, int tab_x_y[2], int ratio)
{
  int   cmpt;
  int   cmpt2;
  t_point first_point;
  t_point p1;
  t_point p2;

  first_point = ft_first_pt(tab_x_y[0], tab_x_y[1], ratio);
  cmpt = 0;
  cmpt2 = 0;
  while (cmpt < tab_x_y[0]) // traits verticaux
  {
    while (cmpt2 < tab_x_y[1] - 1)
    {

      p1.x = first_point.x + ratio * cmpt2;
      p1.y = first_point.y + ratio * cmpt2 - tab[cmpt2][cmpt] * ratio;
      p2.x = first_point.x + ratio * (cmpt2 + 1);
      p2.y = first_point.y + ratio * (cmpt2 + 1) - tab[cmpt2 + 1][cmpt] * ratio;
      ft_draw_line(data, p1, p2);
      cmpt2++;
    }
    first_point.x += ratio;
    first_point.y -= ratio;
    cmpt++;
    cmpt2 = 0;
  }
}

static int	ft_exit_win(int keycode, void *param)
{
	param = NULL;
	if (keycode == 53)
		exit(0);
	return (0);
}

void	ft_draw_fdf(int x, int y, int **tab)
{
  int   ratio;
	t_data data;
  int   tab_x_y[2];
  tab_x_y[0] = x;
  tab_x_y[1] = y;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "fdf");
	ratio = ft_calculate_ratio(x, y, tab);
  ft_draw_vertical(data, tab, tab_x_y, ratio);
  ft_draw_horizontal(data, tab, tab_x_y, ratio);
	mlx_key_hook(data.win, ft_exit_win, 0);
	mlx_loop(data.mlx);
}
