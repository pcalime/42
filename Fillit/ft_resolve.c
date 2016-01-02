/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:16:41 by pcalime           #+#    #+#             */
/*   Updated: 2016/01/02 23:40:25 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_resolve(t_tetrimini *tab_piece, char ***tab_final, int nb, int end)
{
	int	cmpt;

	cmpt = 0;

	ft_affich_tab(tab_final[0]);
	if (nb == end)
		return (1);
	while (cmpt < end)
	{
		if (ft_check_piece(tab_piece[cmpt], tab_final[0]) == 0)
		{
		}
		else
		{
			if (ft_put_all(tab_piece[cmpt], &tab_final[0]))
			{
				if (ft_resolve(tab_piece, &tab_final[0], nb + 1, end))
					return (1);
				ft_remove_piece(tab_piece[cmpt], &tab_final[0]);
			}
		}
		cmpt++;
	}
	return (0);
}
