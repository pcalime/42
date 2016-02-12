/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:14:56 by pcalime           #+#    #+#             */
/*   Updated: 2016/02/12 17:06:47 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	"libft/libft.h"

static	int		ft_is_this_char(char *str, char c)
{
	int		cmpt;

	cmpt = 0;
	while (str[cmpt])
	{
		if (str[cmpt] == c)
			return (1);
	}
	return (0);
}

static	int		ft_fill_line(t_gnl gnl, char *line)
{
	int		cmpt;
	int		len;

	ft_putstr("pouet2");
	while (gnl.ptr[cmpt] && gnl.ptr[cmpt] != '\n')
		cmpt++;
	line = ft_strndup(gnl.ptr, cmpt);
	len = ft_strlen(gnl.ptr);
	gnl.ptr = ft_strndup(&gnl.ptr[cmpt], len - cmpt);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static	t_gnl	gnl;
	int				ret;
	
	if (fd < 0)
		return (-1);
	gnl.buf = malloc(sizeof(char) * BUFF_SIZE);
	gnl.ptr = malloc(sizeof(char) * BUFF_SIZE);
	if (ft_is_this_char(gnl.ptr, '\n') == 1)
		return (ft_fill_line(gnl, *line));
	while ((ret = read(fd, gnl.buf, BUFF_SIZE)))
	{
		ft_putstr("pouet");
		gnl.buf[ret] = '\0';
		gnl.ptr = ft_strjoin(gnl.ptr, gnl.buf);
		if (ft_is_this_char(gnl.buf, '\n') == 1)
			return (ft_fill_line(gnl, *line));
	}
	return (ret);
}
