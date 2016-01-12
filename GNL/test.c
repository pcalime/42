/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 17:39:30 by pcalime           #+#    #+#             */
/*   Updated: 2016/01/10 18:55:07 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	pouet()
{
	static int cmpt = 0;
	cmpt++;
	printf("%d", cmpt);
}

int		main(void)
{
	char	str[] = "paulleplusbo";
	pouet();
	pouet();
	pouet();
	pouet();
	pouet();
	return (0);
}
