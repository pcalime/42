/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 19:06:41 by pcalime           #+#    #+#             */
/*   Updated: 2015/12/18 19:31:55 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_put_vertical_reversed_s(char ***tab, t_tetrimini tab_piece)		// VERIFIE LA PLACE LIBRE OU PAS 
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
			if (tab[0][x + 2][y] == '.' && tab[0][x][y + 1] == '.' && tab[0][x + 1][y + 1] == '.' 
					&& tab[0][x + 2][y + 1] == '.')
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
			if (tab[0][x][y] == '.' && tab[0][x + 1][y] == '.' && tab[0][x + 2][y] == '.' 
					&& tab[0][x + 2][y + 1] == '.')
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
			if (tab[0][x][y] == '.' && tab[0][x][y + 1] == '.' && tab[0][x][y + 2] == '.' 
					&& tab[0][x + 1][y] == '.')
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
			if (tab[0][x][y] == '.' && tab[0][x][y + 1] == '.' && tab[0][x][y + 2] == '.' 
					&& tab[0][x][y + 3] == '.')
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


int			main()
{
	t_tetrimini carre;
	char **tab;
	int i;
	int j;
	int k;

	i = 0;
	tab = (char**)malloc(sizeof(char*) * 1000);
	while (i < 6)
	{
		tab[i] = (char*)malloc(sizeof(char) * 1000);
		i++;
	}
	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = "\0";
	i = 0;
	carre.letter = 'A';
	printf("%d", ft_put_reversed_l(&tab, carre));
	carre.letter = 'B';
	printf("%d", ft_put_vertical_reversed_s(&tab, carre));
	carre.letter = 'C';
	printf("%d", ft_put_l(&tab, carre));
	carre.letter = 'D';
	printf("%d", ft_put_gun(&tab, carre));
	carre.letter = 'E';
	printf("%d", ft_put_horiz_i(&tab, carre));
	carre.letter = 'F';
	printf("%d", ft_put_vertical_reversed_s(&tab, carre));
	carre.letter = 'G';
	printf("%d", ft_put_reversed_l(&tab, carre));
	carre.letter = 'H';
	printf("%d\n", ft_put_gun(&tab, carre));
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
	return(0);

}
