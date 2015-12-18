/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 16:37:10 by pcalime           #+#    #+#             */
/*   Updated: 2015/12/18 16:53:25 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_remove_piece(t_tetrimini tab_piece, char ***tab_final)
{
	int x;
	int y;

	x = 0;
	while (tab_final[0][x])
	{
		y = 0;
		while (tab_final[0][x][y])
		{
			if (tab_piece.letter == tab_final[0][x][y])
				tab_final[0][x][y] = '.';
			y++;
		}
		x++;
	}
}
