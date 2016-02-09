/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:52:37 by pcalime           #+#    #+#             */
/*   Updated: 2016/02/01 16:44:53 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static char	*ft_read_line(char *ptr, int *retour)
{
	static int	cmpt = -1;
	int			cmpt2;

	cmpt2 = 0;
	*retour = 1;
	if (ptr[cmpt] == '\0' && cmpt != -1)
	{
		*retour = 0;
		return (NULL);
	}
	else if (ptr[cmpt] == '\n' && ptr[cmpt + 1] == '\0')
	{
		*retour = 0;
		return (NULL);
	}
	cmpt++;
	while (ptr[cmpt] != '\0' && ptr[cmpt] != '\n')
	{
		cmpt2++;
		cmpt++;
	}
	return (ft_strndup(&ptr[cmpt - cmpt2], cmpt2));
}

static char	*ft_read_fd(int const fd, int *retour)
{
	int		ret;
	char	*buf;
	char	*ptr;

	ret = 0;
	ptr = malloc(sizeof(char) * BUFF_SIZE + 1);
	buf = malloc(sizeof(char) * BUFF_SIZE + 1);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	ptr = ft_strjoin(ptr, buf);
	if (ret == -1)
	{
		*retour = -1;
		return (NULL);
	}
	while (ret)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		ptr = ft_strjoin(ptr, buf);
	}
	return (ptr);
}

int			get_next_line(int const fd, char **line)
{
	int			retour;
	static char	*ptr_final;

	retour = 0;
	if (fd < 0)
		return (-1);
	if (ptr_final == NULL)
		ptr_final = ft_read_fd(fd, &retour);
	if (retour == -1)
		return (retour);
	*line = ft_read_line(ptr_final, &retour);
	return (retour);
}
