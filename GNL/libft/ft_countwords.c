/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 15:13:27 by pcalime           #+#    #+#             */
/*   Updated: 2016/01/28 16:39:22 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static	int	is_sep(char c)
{
	if (c == ' ' || c == '\t' || c == '\0')
		return (0);
	return (1);
}

int			ft_countwords(const char *str)
{
	int		count;
	int		word;

	if (str == NULL)
		return (0);
	word = 0;
	count = 0;
	while (str[count] != '\0')
	{
		if (is_sep(str[count]) && is_sep(str[count + 1]) == 0)
			++word;
		++count;
	}
	return (word);
}
