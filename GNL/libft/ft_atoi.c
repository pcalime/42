/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:56:32 by pcalime           #+#    #+#             */
/*   Updated: 2015/12/03 12:20:47 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int cmpt;
	int number;
	int negative;

	number = 0;
	cmpt = 0;
	negative = 1;
	while (ft_isspace(str[cmpt]))
		cmpt++;
	if (str[cmpt] == '-')
	{
		negative = -1;
	}
	if (str[cmpt] == '+' || str[cmpt] == '-')
		cmpt++;
	while (str[cmpt] >= '0' && str[cmpt] <= '9')
	{
		number *= 10;
		number += str[cmpt] - 48;
		cmpt++;
	}
	return (number *= negative);
}
