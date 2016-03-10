/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:32:12 by pcalime           #+#    #+#             */
/*   Updated: 2016/03/10 12:32:19 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include "get_next_line.h"

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
	ft_putstr("pouet");
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
