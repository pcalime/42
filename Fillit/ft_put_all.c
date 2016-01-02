/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 16:34:35 by pcalime           #+#    #+#             */
/*   Updated: 2016/01/02 23:36:01 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_put_all(t_tetrimini tab_piece, char ***tab_final)
{
	if (ft_put_piece(tab_piece, &tab_final[0]))
		return (1);
	else if (ft_put_piece_2(tab_piece, &tab_final[0]))
		return (1);
	else if (ft_put_piece_3(tab_piece, &tab_final[0]))
		return (1);
	else if (ft_put_piece_4(tab_piece, &tab_final[0]))
		return (1);
	else
		return (0);
}

int		ft_put_piece(t_tetrimini tab_piece, char ***tab_final)
{
	if (tab_piece.forme == 110011)
		return (ft_put_square(&tab_final[0], tab_piece));
	if (tab_piece.forme == 11011)
	{
		if (ft_put_s(&tab_final[0], tab_piece))
			return (1);
	}
	if (tab_piece.forme == 1000110001)
	{
		if (ft_put_vertical_s(&tab_final[0], tab_piece))
			return (1);
	}
	if (tab_piece.forme== 100010011)
	{
		if (ft_put_reversed_l(&tab_final[0], tab_piece))
			return (1);
	}
	if (tab_piece.forme == 111001)
	{
		if (ft_put_t(&tab_final[0], tab_piece))
			return (1);
	}
	return(0);
}

int		ft_put_piece_2(t_tetrimini tab_piece, char ***tab_final)
{
	if (tab_piece.forme == 1100011)
	{
		if (ft_put_reversed_s(&tab_final[0], tab_piece))
			return (1);
	}
	if (tab_piece.forme == 10011001)
	{
		if (ft_put_reversed_vertical_s(&tab_final[0], tab_piece))
			return (1);
	}
	if (tab_piece.forme == 1000100011)
	{
		if (ft_put_l(&tab_final[0], tab_piece))
			return (1);
	}
	if (tab_piece.forme == 11101)
	{
		if (ft_put_gun(&tab_final[0], tab_piece))
			return (1);
	}
	if (tab_piece.forme == 1000100010001)
	{
		if (ft_put_i(&tab_final[0], tab_piece))
			return (1);
	}
	return (0);
}

int		ft_put_piece_3(t_tetrimini tab_piece, char ***tab_final)
{
	if (tab_piece.forme == 10111)
	{
		if (ft_put_pipe(&tab_final[0], tab_piece))
			return (1);
	}
	if (tab_piece.forme == 1110001)
	{
		if (ft_put_reversed_gun(&tab_final[0], tab_piece))
			return (1);
	}
	if (tab_piece.forme == 100011001)
	{
		if (ft_put_right_t(&tab_final[0], tab_piece))
			return (1);
	}
	if (tab_piece.forme == 1100010001)
		return (ft_put_vertical_pipe(&tab_final[0], tab_piece));	
	if (tab_piece.forme == 1000111)
	{
		if (ft_put_reversed_pipe(&tab_final[0], tab_piece))
			return (1);
	}
	return (0);
}

int		ft_put_piece_4(t_tetrimini tab_piece, char ***tab_final)
{
	if (tab_piece.forme == 110010001)
		return (ft_put_reversed_vertical_pipe(&tab_final[0], tab_piece));
	if (tab_piece.forme == 100110001)
	{
		if (ft_put_left_t(&tab_final[0], tab_piece))
			return (1);
	}
	if (tab_piece.forme == 100111)
	{
		if (ft_put_ship(&tab_final[0], tab_piece))
			return (1);
	}
	if (tab_piece.forme == 1111)
	{
		if (ft_put_horiz_i(&tab_final[0], tab_piece))
			return (1);
	}
	return (0);
}
