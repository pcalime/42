/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:46:47 by pcalime           #+#    #+#             */
/*   Updated: 2015/11/30 20:04:57 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1c;
	unsigned char	*s2c;

	i = 0;
	s1c = (unsigned char*)s1;
	s2c = (unsigned char*)s2;
	if (!n)
		return (0);
	while ((s1c[i] == s2c[i]) && s1c[i] && s2c[i] && i < n - 1)
		i++;
	return (s1c[i] - s2c[i]);
}
