/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 19:59:21 by pcalime           #+#    #+#             */
/*   Updated: 2015/12/18 17:21:50 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_recup(t_tetrimini **tab_piece, char *str, int nb_tetri)
{
	char	*tmp;
	char	**piece_split;
	int		cmpt;
	long	tmp_form;

	cmpt = 0;
	if (ft_checkcolonne(str) == 0)
		return (0);
	tmp = ft_no_newline(str);
	piece_split = ft_split_piece(tmp);
	while (cmpt < nb_tetri)
	{
		tmp_form = ft_check(piece_split[cmpt]);
		if (ft_check_tetri(tmp_form) == 0 && ft_check_tetri_1(tmp_form) == 0)
			return (0);
		tab_piece[0][cmpt].letter = 'A' + cmpt;
		tab_piece[0][cmpt].forme = tmp_form;
		cmpt++;
	}
	cmpt = 0;
	return (1);
}
