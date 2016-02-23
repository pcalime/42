/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:32:12 by pcalime           #+#    #+#             */
/*   Updated: 2016/02/23 18:02:10 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

static char	*ft_read(char *str)
{
	int		fd;
	char	*line;
	char	*file;

	file = memaloc(sizeof(char) * 1);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error : Incorrect file name.");
		exit(0);
	}
	while ((get_next_line(fd, &line)))
	{
		file = ft_strjoin(file, line);
		free(line);
	}
	if (close(fd) == -1)
	{
		ft_putstr("Error : Close fail.");
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
		ft_putstr("Error : Too few arguments.");
	else
		ft_putstr("Error : Too much arguments.");
	return (0);
}
