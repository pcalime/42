/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:22:55 by pcalime           #+#    #+#             */
/*   Updated: 2015/11/30 19:32:52 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int	cmpt;

	cmpt = 0;
	while (s[cmpt])
	{
		ft_putchar_fd(s[cmpt], fd);
		cmpt++;
	}
	ft_putchar_fd('\n', fd);
}
