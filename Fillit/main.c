/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 12:31:18 by pcalime           #+#    #+#             */
/*   Updated: 2015/12/15 18:57:27 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(int argc, char **argv)
{
	t_tetrimini	*tab_piece;
	char		*str;
	size_t		nb_tetri;

	if (argc == 2)
	{
		str = malloc(sizeof(char) * BUF_SIZE);
		ft_strcpy(str, ft_read(argv[1]));
		nb_tetri = ft_counttetri(str);
		if (nb_tetri == 0)
		{
			ft_putstr("error\n");
			return (0);
		}
		tab_piece = malloc(sizeof(t_tetrimini) * nb_tetri + 1);
		if (ft_recup(&tab_piece, str, nb_tetri) == 0)
			ft_putstr("error\n");
		int i = 0;
		while (i < 26)
		{
			printf("%ld\n", tab_piece[i].forme);
			printf("%c\n", tab_piece[i].letter);
			i++;
		}
	}
	else
		ft_putstr("error\n");
	return (0);
}
