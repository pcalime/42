/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 19:12:59 by pcalime           #+#    #+#             */
/*   Updated: 2016/01/10 18:55:11 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(const char *s, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			len++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	len;
	size_t	i;
	size_t	cnt;

	cnt = 0;
	len = ft_wordcount(s, c);
	if (len == 0)
		cnt = 1;
	if (!(tab = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = 0;
	while (*s && cnt++ <= ft_wordcount(s, c))
	{
		len = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			s++;
			len++;
		}
		tab[i++] = ft_strndup(s - len, len);
	}
	return (tab);
}
