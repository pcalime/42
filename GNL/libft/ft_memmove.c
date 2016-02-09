/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:35:13 by pcalime           #+#    #+#             */
/*   Updated: 2015/11/30 20:01:16 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;
	char	*dst_cpy;
	char	*src_cpy;

	dst_cpy = (char *)dst;
	src_cpy = (char *)src;
	index = 0;
	if (src_cpy < dst_cpy)
	{
		while (index < len)
		{
			index++;
			dst_cpy[len - index] = src_cpy[len - index];
		}
	}
	else
	{
		while (index < len)
		{
			dst_cpy[index] = src_cpy[index];
			index++;
		}
	}
	return (dst);
}
