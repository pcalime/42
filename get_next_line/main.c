/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 18:45:56 by sguirrie          #+#    #+#             */
/*   Updated: 2016/02/20 16:29:43 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int     main(int argc, char **argv)
{
    int     fd;
    char    *line;
	int		i;

	argc = 0;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        ft_putstr("open() error");
        return (1);
    }
	while ((i = get_next_line((int const)fd, &line)) > 0)
	{
		ft_putstr("LINE\t");
		ft_putendl(line);
        free(line);
	}
    return (1);
}
