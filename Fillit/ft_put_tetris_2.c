/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tetris_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 16:41:54 by pcalime           #+#    #+#             */
/*   Updated: 2016/01/03 02:32:57 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_put_reversed_vertical_s(char ***tab, t_tetrimini tab_piece)
{
	int		x;
	int		y;

	x = 0;
	while (tab[0][x])
	{
		y = 0;
		while (tab[0][x][y])
		{
			if (tab[0][x][y + 1] == '.' && tab[0][x + 1][y] == '.' &&
					tab[0][x + 1][y + 1] == '.' && tab[0][x + 2][y] == '.')
			{
				tab[0][x][y + 1] = tab_piece.letter;
				tab[0][x + 1][y] = tab_piece.letter;
				tab[0][x + 1][y + 1] = tab_piece.letter;
				tab[0][x + 2][y] = tab_piece.letter;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int		ft_put_reversed_l(char ***tab, t_tetrimini tab_piece)
{
	int		x;
	int		y;

	x = 0;
	while (tab[0][x])
	{
		y = 0;
		while (tab[0][x][y])
		{
			if (tab[0][x + 2][y] == '.' && tab[0][x][y + 1] == '.'
				&& tab[0][x + 1][y + 1] == '.' && tab[0][x + 2][y + 1] == '.')
			{
				tab[0][x + 2][y] = tab_piece.letter;
				tab[0][x][y + 1] = tab_piece.letter;
				tab[0][x + 1][y + 1] = tab_piece.letter;
				tab[0][x + 2][y + 1] = tab_piece.letter;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int		ft_put_l(char ***tab, t_tetrimini tab_piece)
{
	int		x;
	int		y;

	x = 0;
	while (tab[0][x])
	{
		y = 0;
		while (tab[0][x][y])
		{
			if (tab[0][x][y] == '.' && tab[0][x + 1][y] == '.'
					&& tab[0][x + 2][y] == '.' && tab[0][x + 2][y + 1] == '.')
			{
				tab[0][x][y] = tab_piece.letter;
				tab[0][x + 1][y] = tab_piece.letter;
				tab[0][x + 2][y] = tab_piece.letter;
				tab[0][x + 2][y + 1] = tab_piece.letter;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int		ft_put_gun(char ***tab, t_tetrimini tab_piece)
{
	int		x;
	int		y;

	x = 0;
	while (tab[0][x])
	{
		y = 0;
		while (tab[0][x][y])
		{
			if (tab[0][x][y] == '.' && tab[0][x][y + 1] == '.'
					&& tab[0][x][y + 2] == '.' && tab[0][x + 1][y] == '.')
			{
				tab[0][x][y] = tab_piece.letter;
				tab[0][x][y + 1] = tab_piece.letter;
				tab[0][x][y + 2] = tab_piece.letter;
				tab[0][x + 1][y] = tab_piece.letter;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int		ft_put_horiz_i(char ***tab, t_tetrimini tab_piece)
{
	int		x;
	int		y;

	x = 0;
	while (tab[0][x])
	{
		y = 0;
		while (tab[0][x][y])
		{
			if (tab[0][x][y] == '.' && tab[0][x][y + 1] == '.'
					&& tab[0][x][y + 2] == '.' && tab[0][x][y + 3] == '.')
			{
				tab[0][x][y] = tab_piece.letter;
				tab[0][x][y + 1] = tab_piece.letter;
				tab[0][x][y + 2] = tab_piece.letter;
				tab[0][x][y + 3] = tab_piece.letter;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}
