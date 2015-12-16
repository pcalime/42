/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counttetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 15:31:27 by pcalime           #+#    #+#             */
/*   Updated: 2015/12/11 17:09:38 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_counttetri(char *str)
{
	int ret;
	int cmpt;

	cmpt = 0;
	ret = 0;
	while (str[cmpt])
	{
		if (str[cmpt] == '\n')
			ret++;
		cmpt++;
	}
	ret++;
	if ((ret % 5 != 0) || (ret > 130))
		return (0);
	ret /= 5;
	return (ret);
}
