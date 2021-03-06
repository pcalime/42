/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affich_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 18:46:29 by pcalime           #+#    #+#             */
/*   Updated: 2016/01/03 02:05:43 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_affich_tab(char **tab_final, int size)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			ft_putchar(tab_final[x][y]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}
