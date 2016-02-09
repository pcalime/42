/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:39:01 by pcalime           #+#    #+#             */
/*   Updated: 2015/12/03 12:21:01 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	cmpt;
	char	*dst_cpy;
	char	*src_cpy;

	if (!dst || !src)
		return (NULL);
	dst_cpy = (char *)dst;
	src_cpy = (char *)src;
	cmpt = 0;
	while (n > 0)
	{
		dst_cpy[cmpt] = src_cpy[cmpt];
		if (src_cpy[cmpt] == c)
			return (dst_cpy + cmpt + 1);
		cmpt++;
		n--;
	}
	return (NULL);
}
