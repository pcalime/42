/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:23:48 by pcalime           #+#    #+#             */
/*   Updated: 2015/12/15 16:22:12 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_check(char *s)  //ENLEVE LES '.' AU DEBUT ET A LA FIN DE LA STRING
{
	char	*s1;
	int		i;
	int		j;

	i = 0;
	while (s[i] == '.')
		i++;
	s1 = (char*)malloc(sizeof(char) * ft_strlen(s));
	j = ft_strlen(s) - 1;
	while (s[j] == '.')
		j--;
	s1 = (ft_strsub(s, i, (j - i) + 1));
	return (ft_recup_tetri(s1));
}

long		ft_recup_tetri(char *str)		// CHANGE LES '.' EN 0 ET LES '#' EN 1
{
	int		i;
	long	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '.')
			str[i] = '0';
		if (str[i] == '#')
			str[i] = '1';
		i++;
	}
	str[i] = '\0';
	ret = ft_atoi(str);
	return (ret);
}
