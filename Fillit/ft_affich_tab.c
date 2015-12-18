/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affich_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 18:46:29 by pcalime           #+#    #+#             */
/*   Updated: 2015/12/18 18:49:50 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_affich_tab(char **tab_final)
{
	int x;
	int y;

	x = 0;
	while (tab_final[x])
	{
		y = 0;
		while (tab_final[x][y])
		{
			ft_putchar(tab_final[x][y]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}
