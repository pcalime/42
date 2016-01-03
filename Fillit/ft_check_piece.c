/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 16:36:10 by pcalime           #+#    #+#             */
/*   Updated: 2016/01/03 02:18:21 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_piece(t_tetrimini tab_piece, char **tab_final)
{
	int x;
	int y;

	x = 0;
	while (tab_final[x])
	{
		y = 0;
		while (tab_final[x][y])
		{
			if (tab_piece.letter == tab_final[x][y])
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
