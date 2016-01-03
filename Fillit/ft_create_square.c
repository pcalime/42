/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 17:10:56 by pcalime           #+#    #+#             */
/*   Updated: 2016/01/03 03:09:39 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_grow_tab(char ***tab, int size)
{
	int	cmpt;
	int	cmpt2;

	cmpt = 0;
	cmpt2 = 0;
	while (cmpt < size)
	{
		cmpt2 = 0;
		while (cmpt2 < size)
		{
			tab[0][cmpt][cmpt2] = '.';
			cmpt2++;
		}
		cmpt++;
	}
}

void	ft_create_square(int end, t_tetrimini *tab_piece)
{
	char	**tab;
	int		nb;
	int		cmpt;
	int		size;
	int		valid;

	nb = 0;
	cmpt = 0;
	valid = 0;
	size = ft_size(end);
	tab = malloc(sizeof(char *) * 15);
	while (cmpt < 15)
	{
		tab[cmpt] = malloc(sizeof(char) * 15);
		cmpt++;
	}
	while (valid == 0)
	{
		ft_grow_tab(&tab, size);
		if (ft_resolve(tab_piece, &tab, nb, end) == 0)
			size++;
		else
			valid++;
	}
	ft_affich_tab(tab, size);
}
