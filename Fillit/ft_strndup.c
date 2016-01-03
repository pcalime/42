/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 20:07:47 by pcalime           #+#    #+#             */
/*   Updated: 2016/01/03 03:04:43 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s2 != NULL)
	{
		while (s1[i] != '\0' && i < len)
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	return (s2);
}
