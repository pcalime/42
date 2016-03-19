/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:32:12 by pcalime           #+#    #+#             */
/*   Updated: 2016/03/19 18:28:20 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_calculate_ratio(int x, int y, int **tab)
{
	int		min;
	int		max;
	int		cmpt;
	int		cmpt2;

	cmpt = 0;
	cmpt2 = 1;
	max = tab[0][0];
	min = tab[0][0];
	while (cmpt < y)
	{
		while (cmpt2 < x)
		{
			if (min > tab[cmpt][cmpt2])
				min = tab[cmpt][cmpt2];
			if (max < tab[cmpt][cmpt2])
				max = tab[cmpt][cmpt2];
			cmpt2++;
		}
		cmpt2 = 0;
		cmpt++;
	}
	cmpt2 = x + y + max / 3 - min / 3 - 1;
	cmpt2 = 1000 / cmpt2;
	return (cmpt2);
}

t_point		ft_first_pt(int x, int y, int ratio)
{
	t_point		f_p;

	f_p.x = (1920 - ratio * (x + y)) / 2;
	f_p.y = ((1080 - ratio * (x + y)) / 2) + ratio * x;
	return (f_p);
}

void		ft_fdf(char *str)
{
	char	*file;
	int		**tab;
	int		x;
	int		y;

	file = ft_read(str);
	if ((x = ft_count_x(file)) == -1)
		exit(0);
	y = ft_count_y(file);
	tab = malloc(sizeof(int *) * y);
	while (--y >= 0)
		tab[y] = malloc(sizeof(int) * x);
	y = ft_count_y(file);
	ft_fill_tab(tab, file, x, y);
	ft_draw_fdf(x, y, tab);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_fdf(argv[1]);
	}
	else if (argc == 1)
		ft_putstr("Error : Too few arguments.\n");
	else
		ft_putstr("Error : Too much arguments.\n");
	return (0);
}
