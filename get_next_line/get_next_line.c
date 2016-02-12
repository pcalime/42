/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:14:56 by pcalime           #+#    #+#             */
/*   Updated: 2016/02/12 15:37:40 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	"libft.h"

int		get_next_line(int const fd, char **line)
{
	static	gnl_t	gnl;
	int		ret;
	
	if (fd < 0)
		return (-1);
	gnl.buf = malloc(sizeof(char) * BUFF_SIZE);
	gnl.ptr = malloc(sizeof(char) * BUFF_SIZE);
	while (ret = read(fd, gnl.buf, BUFF_SIZE))
	{
		if (ret == -1)
			return (ret);
		if (ret == 0)
			return (ret);
		
	}
}
