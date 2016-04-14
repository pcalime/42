/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:39:25 by pcalime           #+#    #+#             */
/*   Updated: 2015/11/30 20:02:33 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		cmpt1;
	int		cmpt2;

	cmpt1 = 0;
	cmpt2 = 0;
	if (!*s2)
		return ((char*)s1);
	while (s1[cmpt1])
	{
		while (s1[cmpt1 + cmpt2] && s1[cmpt1 + cmpt2] == s2[cmpt2])
			cmpt2++;
		if (!s2[cmpt2])
			return ((char *)s1 + cmpt1);
		else
			cmpt2 = 0;
		cmpt1++;
	}
	return (0);
}
