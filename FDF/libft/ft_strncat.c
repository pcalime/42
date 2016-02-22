/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:39:26 by pcalime           #+#    #+#             */
/*   Updated: 2015/11/28 15:51:00 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	cmpt1;
	size_t	cmpt2;

	cmpt1 = ft_strlen(s1);
	cmpt2 = 0;
	while (s2[cmpt2] && cmpt2 < n)
	{
		s1[cmpt1] = s2[cmpt2];
		cmpt1++;
		cmpt2++;
	}
	s1[cmpt1] = '\0';
	return (s1);
}
