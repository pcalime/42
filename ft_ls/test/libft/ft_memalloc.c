/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:59:18 by pcalime           #+#    #+#             */
/*   Updated: 2015/11/30 18:59:46 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char *str;

	str = (char*)malloc(sizeof(char) * size);
	if (size == 0)
		return (NULL);
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	return ((void*)str);
}
