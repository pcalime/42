/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:53:14 by pcalime           #+#    #+#             */
/*   Updated: 2016/02/09 17:14:40 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define BUFF_SIZE 100

typedef static struct	gnl_s
{
	int fd;
	char *buf;
	char *ptr;
}						gnl_t;

int		get_next_line(int const fd, char **line);

#endif
