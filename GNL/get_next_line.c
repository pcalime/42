/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:52:37 by pcalime           #+#    #+#             */
/*   Updated: 2016/01/12 15:37:30 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_read_line(char *ptr, int *retour)
{
	static int	cmpt = 0;
	int			cmpt2;

	printf("%d", cmpt);
	ft_putstr(ptr);
	cmpt2 = 0;
	*retour = 1;
	while (ptr[cmpt] != '\0')
	{
		if (ptr[cmpt] == '\n')
		{
			return (ft_strndup(&ptr[cmpt - cmpt2], cmpt2));
		}
		cmpt2++;
		cmpt++;
	}
	if (ptr[cmpt] == '\0')
	{
		*retour = 0;
		return (ft_strndup(&ptr[cmpt - cmpt2], cmpt2));
		
	}
	*retour = -1;
	return (NULL);
}

int		get_next_line(int const fd, char **line)
{
	int			ret;
	char		*buf;
	char		*ptr;
	int			retour;

	ptr = malloc(sizeof(char) * BUF_SIZE + 1);
	buf = malloc(sizeof(char) * BUF_SIZE + 1);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	ptr = ft_strjoin(ptr, buf);
	while (ret)
	{
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		ptr = ft_strjoin(ptr, buf);
	}
	*line = ft_read_line(ptr, &retour);
 	return (retour);
}

int		main(int argc, char **argv)
{
	int fd;
	char *line;

	line = malloc(sizeof(char) * BUF_SIZE + 1);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		get_next_line(fd, &line);
		printf("%s", line);
		get_next_line(fd, &line);
		printf("%s", line);
		get_next_line(fd, &line);
		printf("%s", line);
		get_next_line(fd, &line);
		printf("%s", line);
	}
}
