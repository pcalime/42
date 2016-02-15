/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:34:37 by pcalime           #+#    #+#             */
/*   Updated: 2016/02/15 14:28:16 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	fd;
	int ret;
	char *line;

	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%d : %s\n", ret, line);
		free (line);
	}
	printf("%d : %s\n", ret, line);
	return (0);
}
