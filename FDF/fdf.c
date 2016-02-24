/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:32:12 by pcalime           #+#    #+#             */
/*   Updated: 2016/02/24 18:37:41 by pcalime          ###   ########.fr       */
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

void		ft_fdf(char *str)
{
	char	*file;

	file = ft_read(str);
	ft_putstr(file);
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
