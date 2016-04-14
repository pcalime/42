/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:03:00 by pcalime           #+#    #+#             */
/*   Updated: 2015/11/30 20:01:52 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(s2);
	if (s2[i] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0' && i < (n - len + 1))
	{
		if (ft_strncmp(&s1[i], s2, len) == 0)
			return ((char*)&s1[i]);
		i++;
	}
	return (0);
}
