/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:16:41 by pcalime           #+#    #+#             */
/*   Updated: 2016/01/03 02:58:24 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_resolve(t_tetrimini *tab_pie, char ***tab, int nb, int end)
{
	int	cmpt;

	cmpt = 0;
	if (nb == end)
		return (1);
	while (cmpt < end)
	{
		if (ft_check_piece(tab_pie[cmpt], tab[0]) == 0)
		{
		}
		else
		{
			if (ft_put_all(tab_pie[cmpt], &tab[0]))
			{
				if (ft_resolve(tab_pie, &tab[0], nb + 1, end))
					return (1);
				ft_remove_piece(tab_pie[cmpt], &tab[0]);
			}
		}
		cmpt++;
	}
	return (0);
}
