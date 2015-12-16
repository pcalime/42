/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:15:15 by pcalime           #+#    #+#             */
/*   Updated: 2015/12/11 17:31:05 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long			ft_atoi(const char *str)
{
	long nbr;
	long neg;

	neg = 1;
	nbr = 0;
	if (!str)
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (ft_isdigit((long)*str))
	{
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	return (neg * nbr);
}
