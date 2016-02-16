/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:58:23 by pcalime           #+#    #+#             */
/*   Updated: 2016/02/16 14:18:59 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include "get_next_line.h"

static void init_buf(t_gnl **gnl, char **line)
{
	*line = (char *)ft_memalloc(1);
	if (!*gnl)
	{
		*gnl = (t_gnl *)ft_memalloc(sizeof(t_gnl));
		(*gnl)->buf = (char *)ft_memalloc (BUFF_SIZE + 1);
		(*gnl)->ptr = NULL;
	}
}

int		get_next_line(int const fd, char **line)
{
	static t_gnl	*gnl = NULL;
	int				ret;

	init_buf(&gnl, line);
	if (gnl->ptr)
	{
		*line = ft_fill_line(gnl->ptr + 1, *line);
		if ((gnl->ptr = ft_strchr(gnl->ptr + 1, '\n')) == NULL)
		{
			
		}
	}
}
