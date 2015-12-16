/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:24:08 by pcalime           #+#    #+#             */
/*   Updated: 2015/12/15 19:24:13 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_resolve(t_tetrimini *tab_piece, char ***tab_final, int nb, int end) //end ==ft_counttetri
{
	int cmpt;

	if (nb == end) (on a fini le tableau est rempli)
		return (1);
	while (cmpt < end)
	{
		fonction qui regarde si la piece(tab_piece[cmpt]) et deja placer (cherche la lettre)	
			si oui -->cmpt++;(on essaye de placer une autre piece)
			si non -->put_piece;(rentre la piece dans le tableau)
				-->si put_piece return(0)
					cmpt++;
				-->si put_piece return(1) (alors if resolve nb++)
				if (ft_resolve(nb++))(passe a la recursive suivante)
					return (1);(si toute les recursive return(1) alors c GG)
			ft_retire la piece;(recupe la lettre(tab_piece[cmpt].letter) et la remplace par des '.')
	}
	return (0); (la fonction revient a la recursive d avant et reprend la ou elle etait)
}
