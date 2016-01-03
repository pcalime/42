/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:11:48 by pcalime           #+#    #+#             */
/*   Updated: 2016/01/03 03:07:23 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	cmpt;
	size_t	len;

	cmpt = 0;
	len = ft_strlen(src);
	while (cmpt < n)
	{
		if (cmpt > len)
			dst[cmpt] = '\0';
		else
			dst[cmpt] = src[cmpt];
		cmpt++;
	}
	return (dst);
}
