/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:22:58 by pcalime           #+#    #+#             */
/*   Updated: 2015/12/18 16:46:57 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_check_tetri(long n)  // RECUPERE L INT DE RECUP TETRIS ET VERIFIE LES ID 
{
	long	tab[10];
	int		i;

	i = 0;
	tab[0] = 110011;		//CARRE
	tab[1] = 1100011;		//S Inverse
	tab[2] = 11011;			//S
	tab[3] = 1000110001;	//S Vertical
	tab[4] = 10011001;		//S Inverse Vertical
	tab[5] = 111001;		//T
	tab[6] = 100010011;		//L Inverse
	tab[7] = 1000100011;	//L
	tab[8] = 100110001;		//T a Gauche
	tab[9] = 110010001;		// L Inverse en bas
	while (i <= 9)
	{
		if (tab[i] == n)
			return (1);
		i++;
	}
	return (0);
}

int			ft_check_tetri_1(long n)
{
	long	tab[9];
	int		i;

	i = 0;
	tab[0] = 11101;		//L en bas
	tab[1] = 1111;		// Barre Horizontale
	tab[2] = 1000100010001;	// Barre verticale
	tab[3] = 1000110001;	//T a Droite
	tab[4] = 10111;			//L tete en haut
	tab[5] = 1110001;		//L inverse couche
	tab[6] = 1100010001;	// L Inverse
	tab[7] = 1000111;		//L inverse tete en haut
	tab[8] = 100111;		//T vers le haut

	while (i <= 8 )
	{
		if (tab[i] == n)
			return (1);
		i++;
	}
	return (0);
}
