/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 12:31:18 by pcalime           #+#    #+#             */
/*   Updated: 2016/01/02 23:35:53 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(int argc, char **argv)
{
	t_tetrimini	*tab_piece;
	char		*str;
	int			nb_tetri;

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
		ft_create_square(nb_tetri, tab_piece);
	}
	else
		ft_putstr("error\n");
	return (0);
}
