/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:57:55 by pcalime           #+#    #+#             */
/*   Updated: 2016/01/03 03:01:59 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int		cmpt;

	cmpt = 0;
	while (src[cmpt])
	{
		dst[cmpt] = src[cmpt];
		cmpt++;
	}
	return (dst);
}
