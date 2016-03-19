/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:59:49 by pcalime           #+#    #+#             */
/*   Updated: 2016/02/12 16:45:17 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		cmpt;
	char	*s1;

	s1 = (char*)s;
	cmpt = ft_strlen(s1);
	while (cmpt >= 0)
	{
		if (s1[cmpt] == c)
		{
			return (s1 + cmpt);
		}
		cmpt--;
	}
	return (0);
}
