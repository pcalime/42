/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 19:26:55 by pcalime           #+#    #+#             */
/*   Updated: 2015/11/30 19:27:11 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\v' ||
			c == '\f')
		return (1);
	return (0);
}