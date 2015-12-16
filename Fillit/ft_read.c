/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 18:30:16 by pcalime           #+#    #+#             */
/*   Updated: 2015/12/11 17:08:38 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read(char *str)
{
	int		fd;
	int		ret;
	char	*buf;

	buf = malloc(sizeof(char) * BUF_SIZE);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (close(fd) == -1)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	return (buf);
}
