/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:48:53 by pcalime           #+#    #+#             */
/*   Updated: 2015/11/30 20:03:57 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			cmpt;
	unsigned char	*str;

	str = (unsigned char *)b;
	cmpt = 0;
	while (cmpt < len)
	{
		str[cmpt] = c;
		cmpt++;
	}
	return (str);
}
