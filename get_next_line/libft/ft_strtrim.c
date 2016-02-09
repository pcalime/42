/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 19:12:12 by pcalime           #+#    #+#             */
/*   Updated: 2015/11/30 20:04:19 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s1;
	int		j;
	size_t	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if (i == ft_strlen(s))
		return (ft_strdup(""));
	s1 = (char*)malloc(sizeof(char) * ft_strlen(s));
	j = ft_strlen(s) - 1;
	while (ft_isspace(s[j]))
		j--;
	s1 = (ft_strsub(s, i, (j - i + 1)));
	return (s1);
}
