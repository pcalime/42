/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 19:13:57 by pcalime           #+#    #+#             */
/*   Updated: 2015/11/30 20:06:00 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count(int i)
{
	int k;

	k = 0;
	while (i > 0)
	{
		i /= 10;
		k++;
	}
	return (k);
}

static char	*ft_check_errors(int c)
{
	if (c == 0)
		return (ft_strdup("0"));
	if (c == -2147483648)
		return (ft_strdup("-2147483648"));
	return (0);
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	i;
	int				k;

	str = (char*)malloc(sizeof(char) * 10);
	k = 0;
	if (n == 0 || n == -2147483648)
		return (ft_check_errors(n));
	if (n < 0)
	{
		str[0] = '-';
		k++;
		n = n * -1;
	}
	i = n;
	k += ft_count(i);
	str[k + 1] = '\0';
	while (n > 0)
	{
		k--;
		str[k] = n % 10 + 48;
		n /= 10;
	}
	return (str);
}
