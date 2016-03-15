/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:11:13 by pcalime           #+#    #+#             */
/*   Updated: 2016/03/15 20:01:46 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_fill_file(char *line, char *file)
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

char		*ft_read(char *str)
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
