/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:57:04 by pcalime           #+#    #+#             */
/*   Updated: 2015/11/30 19:29:46 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t cmpt;

	cmpt = 0;
	while (cmpt < n && s)
	{
		if (*((char *)s + cmpt) == (char)c)
			return ((void *)((char *)s + cmpt));
		cmpt++;
	}
	return (0);
}
