/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int_to_bit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <pcalime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 20:05:00 by pcalime           #+#    #+#             */
/*   Updated: 2016/06/23 01:02:23 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*convert_int_to_bit(int nbr)
{
	int		cmpt;
	int		cmpt2;
	char	tmp[32];
	char	*ret;

	ret = (char *)ft_memalloc(sizeof(char) * 33);
	if (nbr < 0)
		return (ft_strdup("0"));
	cmpt = 0;
	while (cmpt < 32)
	{
		tmp[cmpt] = nbr % 2 + 48;
		nbr /= 2;
		cmpt++;
	}
	cmpt2 = -1;
	while (++cmpt2 < 32)
	{
		cmpt--;
		ret[cmpt2] = tmp[cmpt];
	}
	return (ret);
}
