/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:31:20 by pcalime           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/12/10 21:57:58 by pcalime          ###   ########.fr       */
=======
/*   Updated: 2015/12/10 20:05:09 by atrang           ###   ########.fr       */
>>>>>>> d1ee8ae3d2ee60196fbba957dad2c2ee25096d46
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_put_square(char ***tab, t_tetrimini tab_piece)
{
	int		x;
	int		y;

	x = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if (tab[0][x][y] == '0' && tab[0][x + 1][y] == '0' && tab[0][x][y + 1] == '0' 
					&& tab[0][x + 1][y + 1] == '0')
			{
				tab[0][x][y] = tab_piece.letter;
				tab[0][x + 1][y] = tab_piece.letter;
				tab[0][x][y + 1] = tab_piece.letter;
				tab[0][x + 1][y + 1] = tab_piece.letter;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int		ft_put_s(char ***tab, t_tetrimini tab_piece)
{
	int		x;
	int		y;

	x = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if (tab[0][x][y] == '0' && tab[0][x][y + 1] == '0' && tab[0][x + 1][y + 1] == '0' 
					&& tab[0][x + 1][y + 2] == '0')
			{
				tab[0][x][y] = tab_piece.letter;
				tab[0][x][y + 1] = tab_piece.letter;
				tab[0][x + 1][y + 1] = tab_piece.letter;
				tab[0][x + 1][y + 2] = tab_piece.letter;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}
int			main()
{
	t_tetrimini carre;
	char **tab;
	int i;
	int j;
	int k;

	i = 0;
	tab = (char**)malloc(sizeof(char*) * 6);
	while (i < 6)
	{
		tab[i] = (char*)malloc(sizeof(char) * 6);
		i++;
	}
	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			tab[i][j] = '0';
			j++;
		}
		i++;
	}
	tab[1][1] = '1';
	i = 0;
	carre.letter = 'A';
	ft_put_s(&tab, carre);
	while (i < 6)
	{
		printf("%c", tab[i][0]);
		printf("%c", tab[i][1]);
		printf("%c", tab[i][2]);
		printf("%c", tab[i][3]);
		printf("%c", tab[i][4]);
		printf("%c", tab[i][5]);
		printf("\n");
		i++;
	}
	return (0);
}
/*nt		ft_put_square(char ***tab, t_tetrimini tab_piece)
{
	int		x;
	int		y;

	x = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if (tab[0][x][y] == '0' && tab[0][x + 1][y] == '0' && tab[0][x][y + 1] == '0' 
					&& tab[0][x + 1][y + 1] == '0')
			{
				tab[0][x][y] = tab_piece.letter;
				tab[0][x + 1][y] = tab_piece.letter;
				tab[0][x][y + 1] = tab_piece.letter;
				tab[0][x + 1][y + 1] = tab_piece.letter;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}
*/







