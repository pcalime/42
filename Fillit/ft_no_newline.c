/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_newline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:36:10 by pcalime           #+#    #+#             */
/*   Updated: 2015/12/10 17:32:55 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_no_newline(char *str)
{
	char	*ret;
	int		cmpt;
	int		cmpt2;

	cmpt = 0;
	cmpt2 = 0;
	ret = malloc(sizeof(char) * BUF_SIZE);
	while (str[cmpt])
	{
		if (str[cmpt] != '\n')
		{
			ret[cmpt2] = str[cmpt];
			cmpt2++;
		}
		cmpt++;
	}
	ret[cmpt2] = '\0';
	return (ret);
}
