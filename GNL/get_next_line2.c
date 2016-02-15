/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:14:56 by pcalime           #+#    #+#             */
/*   Updated: 2016/02/15 12:42:40 by pcalime          ###   ########.fr       */
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
	ft_putstr(gnl.ptr);
	return (line);
}

int				get_next_line(int const fd, char **line)
{
	static	t_gnl	gnl;
	int				ret;

	if (fd < 0)
		return (-1);
	*line = (char *)ft_memalloc(1);
	if (gnl.buf == NULL)
	{
		ft_putstr("pouet5");
		gnl.buf = malloc(sizeof(char) * BUFF_SIZE);
		gnl.ptr = malloc(sizeof(char) * BUFF_SIZE);
	}
	ft_putstr(gnl.ptr);
	if (ft_is_this_char(gnl.ptr, '\n') == 1)
	{
		ft_putstr("pouet1");
		*line = ft_fill_line(gnl);
		return (1);
	}
	while ((ret = read(fd, gnl.buf, BUFF_SIZE)))
	{
		gnl.buf[ret] = '\0';
		gnl.ptr = ft_strjoin(gnl.ptr, gnl.buf);
		ft_putstr("pouet2");
		if (ft_is_this_char(gnl.ptr, '\n') == 1)
		{
			ft_putstr("pouet3");
			*line = ft_fill_line(gnl);
			ft_putstr(gnl.ptr);
			return (1);
		}
	}
	return (ret);
}
