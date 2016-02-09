/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:24:54 by pcalime           #+#    #+#             */
/*   Updated: 2015/11/30 19:28:59 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	cmpt;
	char	*dst_cpy;
	char	*src_cpy;

	dst_cpy = (char *)dst;
	src_cpy = (char *)src;
	cmpt = 0;
	if (!dst || !src)
		return (0);
	while (cmpt < n)
	{
		dst_cpy[cmpt] = src_cpy[cmpt];
		cmpt++;
	}
	return (dst_cpy);
}
