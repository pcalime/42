/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:32:12 by pcalime           #+#    #+#             */
/*   Updated: 2016/03/15 18:15:40 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_calculate_ratio(int x, int y, int **tab) // a finir
{
	int		min;
	int		max;
	int		cmpt;
	int		cmpt2;
	int		hauteur;

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
	hauteur = x + y + max - min - 1;
	hauteur = 1000 / hauteur;
	printf("%d\n", hauteur);
	return (hauteur);
}

t_point	ft_first_pt(int x, int y, int ratio) //a faire
{
	t_point		lol;
	lol.x = 500;
	lol.y = 700;
	x = 3;
	y += x;
	ratio = 34;
	return (lol);
}

void		ft_fdf(char *str)
{
	char	*file;
	int		**tab;
	int		x;
	int		y;
	int		cmpt;
	int		cmpt2;

	file = ft_read(str);
	if ((x = ft_count_x(file)) == -1)
		exit(0);
	y = ft_count_y(file);
	tab = malloc(sizeof(int *) * y);
	while (--y >= 0)
		tab[y] = malloc(sizeof(int) * x);
	y = ft_count_y(file);
	ft_fill_tab(tab, file, x, y);
	cmpt = 0;
	cmpt2 = 0;
	while (cmpt < y)
	{
		while (cmpt2 < x)
		{
			printf("%d ", tab[cmpt][cmpt2]);
			cmpt2++;
		}
		printf("\n");
		cmpt++;
		cmpt2 = 0;
	}
	ft_draw_fdf(x, y, tab);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_fdf(argv[1]);
	}
	else if (argc == 1)
		perror("Error");
	//		ft_putstr("Error : Too few arguments.\n");
	else
		perror("Error");
	//ft_putstr("Error : Too much arguments.\n");
	return (0);
}
