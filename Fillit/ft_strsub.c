/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 19:08:49 by pcalime           #+#    #+#             */
/*   Updated: 2016/01/03 03:06:24 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	str = (char*)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	ft_strncpy(str, &s[start], len);
	return (str);
}
