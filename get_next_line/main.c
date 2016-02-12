/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:32:17 by pcalime           #+#    #+#             */
/*   Updated: 2016/02/12 17:56:27 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

int     main()
{
	int     fd;
	char    *line;
	int		i;

	fd = open("test", O_RDONLY);
	while ((i = get_next_line((int const)fd, &line)) > 0)
	{
		printf("%d %s\n", i, line);
		free (line);
	}
	printf("%d %s\n", i, line);
	return (1);
}
