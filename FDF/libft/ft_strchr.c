/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:48:47 by pcalime           #+#    #+#             */
/*   Updated: 2015/11/30 20:00:52 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (c == '\0')
	{
		i = ft_strlen(s);
		return ((char*)s + i);
	}
	while (s[i])
	{
		if ((char)c == s[i])
			return ((char*)s + i);
		i++;
	}
	return (NULL);
}
