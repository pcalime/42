/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:26:07 by pcalime           #+#    #+#             */
/*   Updated: 2016/01/08 17:11:45 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int cmpt;
	int cmpt2;

	cmpt = 0;
	cmpt2 = ft_strlen(s1);
	while (s2[cmpt])
	{
		s1[cmpt2] = s2[cmpt];
		cmpt++;
		cmpt2++;
	}
	s1[cmpt2] = '\0';
	return (s1);
}
