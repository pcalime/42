/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:32:12 by pcalime           #+#    #+#             */
/*   Updated: 2016/03/12 18:35:09 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include "get_next_line.h"

int			ft_exit_win(int keycode, void *param)
{
	param = NULL;
	if (keycode == 53)
		exit(0);
	return (0);
}

char		*ft_fill_file(char *line, char *file)
{
	char	*tmp;
	int		cmpt;
	int		cmpt2;

	cmpt = 0;
	cmpt2 = -1;
	while (line[cmpt] != '\0' && line[cmpt] != '\n')
		cmpt++;
	tmp = file;
	file = (char *)ft_memalloc(sizeof(char) * (ft_strlen(file) + cmpt) + 2);
	cmpt = -1;
	while (tmp[++cmpt] != '\0')
		file[cmpt] = tmp[cmpt];
	while (line[++cmpt2] != '\0' && line[cmpt2] != '\n')
	{
		file[cmpt] = line[cmpt2];
		cmpt++;
	}
	file[cmpt] = '\n';
	free(tmp);
	return (file);
}


static char	*ft_read(char *str)
{
	int		fd;
	char	*line;
	char	*file;

	file = (char *)ft_memalloc(1);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit(0);
	}
	while (get_next_line(fd, &line) == 1)
	{
		file = ft_fill_file(line, file);
		free(line);
	}
	if (close(fd) == -1)
	{
		perror("Error");
		exit(0);
	}
	return (file);
}

static int	ft_count_x(char *str)
{
	int		x;
	int		cmpt;
	int		cmpt_first_l;

	cmpt = 0;
	x = 0;
	cmpt_first_l = 0;
	while (str[cmpt] != '\n' && str[cmpt])
	{
		while (ft_isspace(str[cmpt]) && str[cmpt] && str[cmpt] != '\n')
			cmpt++;
		if (str[cmpt] != '\n')
			cmpt_first_l++;
		while ((ft_isspace(str[cmpt]) == 0) && str[cmpt])
			cmpt++;
	}
	cmpt++;
	while (str[cmpt])
	{
		while (str[cmpt] != '\n')
		{
			while (ft_isspace(str[cmpt]) && str[cmpt] && str[cmpt] != '\n')
				cmpt++;
			if (str[cmpt] != '\n')
				x++;
			while ((ft_isspace(str[cmpt]) == 0) && str[cmpt])
				cmpt++;
		}
		if (str[cmpt] == '\n')
		{
			if (x < cmpt_first_l)
				return (-1);
			x = 0;
			cmpt++;
		}
	}
	return (cmpt_first_l);
}

static int	ft_count_y(char *str)
{
	int		cmpt;
	int		y;

	cmpt = 0;
	y = 0;
	while (str[cmpt])
	{
		if (str[cmpt] == '\n')
			y++;
		cmpt++;
	}
	return (y);
}

#include <stdio.h>

static void		ft_fill_tab(int **tab, char *str, int x, int y)
{
	int		cmpt;
	int		x_cmpt;
	int		y_cmpt;

	x_cmpt = 0;
	y_cmpt = 0;
	cmpt = 0;
//	ft_putnbr(y);
//	ft_putnbr(x);
	while (y_cmpt < y)
	{
		while (x_cmpt < x)
		{
//			ft_putnbr(y_cmpt);
//			ft_putnbr(x_cmpt);
			while (ft_isspace(str[cmpt]))
				cmpt++;
			tab[y_cmpt][x_cmpt] = ft_atoi(&str[cmpt]);
			while (ft_isspace(str[cmpt]) == 0 && str[cmpt])
				cmpt++;
			x_cmpt++;
		}
		x_cmpt = 0;
		y_cmpt++;
	}
}

/*static void	ft_fill_tab(int	**tab, char *str, int x, int y)
{
	int		cmpt;
	//char	**split;
	int		x_cmpt;
	int		y_cmpt;

	x_cmpt = 0;
	y_cmpt = 0;
	cmpt = 0;
	ft_putstr(str);
	while (str[cmpt])
	{
		if (str[cmpt] == '\n')
			str[cmpt] = ' ';
		cmpt++;
	}
	//ft_putstr(str);
	//split = ft_strsplit(str, ' '); // faire strsplit a la main
	cmpt = 0;
	ft_putnbr(x);
	ft_putnbr(y);
	while (y_cmpt < y)
	{
		while (x_cmpt < x)
		{
			ft_putstr(" ");
			ft_putnbr(cmpt);
	//		ft_putstr(split[cmpt]);
			tab[y_cmpt][x_cmpt] = 0;//ft_atoi(&str[cmpt]);
			cmpt++;
			x_cmpt++;
		}
		y_cmpt++;
		x_cmpt = 0;
	}
}
*/

void			ft_draw_fdf(t_point **tab, int x, int y)
{
	int		cmpt;
	int		cmpt2;
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "fdf");
	cmpt = 0;
	cmpt2 = 0;
	while (cmpt2 < y - 1)
	{
		while (cmpt < x - 1)
		{
			ft_draw_line(data, tab[cmpt2][cmpt], tab[cmpt2 + 1][cmpt]);
			ft_draw_line(data, tab[cmpt2][cmpt], tab[cmpt2][cmpt + 1]);
			cmpt++;
		}
		cmpt = 0;
		cmpt2++;
	}
	mlx_key_hook(data.win, ft_exit_win, 0);
	mlx_loop(data.mlx);
}

static int		ft_calculate_ratio(int x, int y, int **tab) // a finir
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

static t_point	ft_first_pt(int x, int y, int ratio) //a faire
{
	t_point		lol;
	lol.x = 500;
	lol.y = 800;
	x = 3;
	y += x;
	ratio = 34;
	return (lol);
}

void			ft_affich_tab_pts(t_point **tab_pts, int x, int y)
{
	int		cmpt;
	int		cmpt2;

	cmpt = 0;
	cmpt2 = 0;
	while (cmpt2 < y) // re affichage
	{
		while (cmpt < x)
		{
			printf("%f,%f ; ", tab_pts[cmpt2][cmpt].x, tab_pts[cmpt2][cmpt].y);
			cmpt++;
		}
		printf("\n");
		cmpt = 0;
		cmpt2++;
	}
	printf("\n");
}

void			ft_create_tab_point(int x, int y, int **tab)
//creer deux points et les faire tracer des droites
//tracer d abord horizontal puis vertical
{
	int		cmpt;
	int		cmpt2;
	t_point	**tab_pts;
	int		ratio;
	t_point	first_point;

	cmpt = -1;
	tab_pts = (t_point **)malloc(sizeof(t_point *) * y);
	while (++cmpt <= y)
		tab_pts[cmpt] = malloc(sizeof(int) * x);
	ratio = ft_calculate_ratio(x, y, tab); // a finir
	first_point = ft_first_pt(x, y, ratio);
	//calculer le premier point(a gauche)
	//calculer le ratio entre deux pts
	//remplir le tableau de points
	cmpt = 0;
	cmpt2 = 0;
	ft_affich_tab_pts(tab_pts, x, y);
	while (cmpt2 < y)
	{
		while (cmpt < x)
		{
			tab_pts[cmpt2][cmpt].x = first_point.x + ratio * cmpt + ratio * cmpt2;
			tab_pts[cmpt2][cmpt].y = first_point.y - ratio * cmpt + ratio * cmpt2 - tab[cmpt2][cmpt] * ratio;
			printf("%d,%d\n", cmpt2, cmpt);
			ft_affich_tab_pts(tab_pts, x, y);
			//printf("%f,%f ; ", tab_pts[cmpt2][cmpt].x, tab_pts[cmpt2][cmpt].y); //affichage
			cmpt++;
		}
		//printf("\n");
		cmpt = 0;
		cmpt2++;
	}
	//printf("\n");
	ft_affich_tab_pts(tab_pts, x, y);
	ft_draw_fdf(tab_pts, x, y);
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
	ft_create_tab_point(x, y, tab);
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
