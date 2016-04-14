/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 19:11:01 by pcalime           #+#    #+#             */
/*   Updated: 2016/02/24 18:10:18 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	return (str);
}
