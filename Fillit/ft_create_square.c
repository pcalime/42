/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 17:10:56 by pcalime           #+#    #+#             */
/*   Updated: 2015/12/18 19:31:07 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_create_square(int end, t_tetrimini *tab_piece)
{	
	char	**tab;
	int		nb;
	int		cmpt;
	int		cmpt2;
	//int		size
	
	nb = 0;
	cmpt = 0;
	//size = ft_size(end);
	tab = malloc(sizeof(char *) * 5);
	while (cmpt < 4)
	{
		tab[cmpt] = malloc(sizeof(char) * 5);
		cmpt ++;
	}
	cmpt = 0;
	while (cmpt < 4)
	{
		cmpt2 = 0;
		while (cmpt2 < 4)
		{
			tab[cmpt][cmpt2] = '.';
			cmpt2++;
		}
		cmpt++;
	}
	ft_resolve(tab_piece, &tab, nb, end);
}
