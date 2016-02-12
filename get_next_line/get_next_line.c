/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:14:56 by pcalime           #+#    #+#             */
/*   Updated: 2016/02/12 17:56:30 by pcalime          ###   ########.fr       */
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
		{
			return (1);
		}
		cmpt++;
	}
	return (0);
}

static	char		*ft_fill_line(t_gnl gnl)
{
	int		cmpt;
	int		len;
	char	*tmp;
	char	*line;

	cmpt = 0;
	while (gnl.ptr[cmpt] && gnl.ptr[cmpt] != '\n')
		cmpt++;
	line = ft_strndup(gnl.ptr, cmpt);
	len = ft_strlen(gnl.ptr);
	tmp = gnl.ptr;
	free(gnl.ptr);
	gnl.ptr = ft_strndup(&tmp[cmpt + 1], len - cmpt);
	return (line);
}

int				get_next_line(int const fd, char **line)
{
	static	t_gnl	gnl;
	int				ret;

	*line = (char *)ft_memalloc(1);
	if (fd < 0)
		return (-1);
	gnl.buf = malloc(sizeof(char) * BUFF_SIZE);
	gnl.ptr = malloc(sizeof(char) * BUFF_SIZE);
	if (ft_is_this_char(gnl.ptr, '\n') == 1)
	{
		*line = ft_fill_line(gnl);
		return (1);
	}
	while ((ret = read(fd, gnl.buf, BUFF_SIZE)))
	{
		gnl.buf[ret] = '\0';
		gnl.ptr = ft_strjoin(gnl.ptr, gnl.buf);
		if (ft_is_this_char(gnl.ptr, '\n') == 1)
		{
			*line = ft_fill_line(gnl);
			return (1);
		}
	}
	return (ret);
}
