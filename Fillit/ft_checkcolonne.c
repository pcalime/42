/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkcolonne.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 18:55:15 by pcalime           #+#    #+#             */
/*   Updated: 2015/12/10 21:57:50 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		ft_checkcolonne(char *str)
{
	int		cmpt;
	int		check;

	cmpt = 0;
	check = 1;
	while (str[cmpt])
	{
		if (((cmpt + 1) % 21 == 0) && (check != 1))
			return (0);
		else if (str[cmpt] == '\n' && (cmpt + 1) % 21 != 0)
		{
			if (check != 5)
				return (0);
		}
		if (str[cmpt] == '\n')
			check = 0;
		if (str[cmpt] != '\n' && str[cmpt] != '#' && str[cmpt] != '.')
			return (0);
		cmpt++;
		check++;
	}
	return (1);
}
