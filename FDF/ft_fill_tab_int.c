/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tab_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:14:30 by pcalime           #+#    #+#             */
/*   Updated: 2016/03/15 13:25:01 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_count_x(char *str)
{
	int		x;
	int		cmpt;
	int		cmpt_first_l;

	cmpt = 0;
	x = 0;
	cmpt_first_l = 0;
	while (str[cmpt] != '\n' && str[cmpt])
	{
		while (ft_isspace(str[cmpt]) && str[cmpt] && str[cmpt] != '\n')
			cmpt++;
		if (str[cmpt] != '\n')
			cmpt_first_l++;
		while ((ft_isspace(str[cmpt]) == 0) && str[cmpt])
			cmpt++;
	}
	cmpt++;
	while (str[cmpt])
	{
		while (str[cmpt] != '\n')
		{
			while (ft_isspace(str[cmpt]) && str[cmpt] && str[cmpt] != '\n')
				cmpt++;
			if (str[cmpt] != '\n')
				x++;
			while ((ft_isspace(str[cmpt]) == 0) && str[cmpt])
				cmpt++;
		}
		if (str[cmpt] == '\n')
		{
			if (x < cmpt_first_l)
				return (-1);
			x = 0;
			cmpt++;
		}
	}
	return (cmpt_first_l);
}

int		ft_count_y(char *str)
{
	int		cmpt;
	int		y;

	cmpt = 0;
	y = 0;
	while (str[cmpt])
	{
		if (str[cmpt] == '\n')
			y++;
		cmpt++;
	}
	return (y);
}

void	ft_fill_tab(int **tab, char *str, int x, int y)
{
	int		cmpt;
	int		x_cmpt;
	int		y_cmpt;

	x_cmpt = 0;
	y_cmpt = 0;
	cmpt = 0;
	while (y_cmpt < y)
	{
		while (x_cmpt < x)
		{
			while (ft_isspace(str[cmpt]))
				cmpt++;
			tab[y_cmpt][x_cmpt] = ft_atoi(&str[cmpt]);
			while (ft_isspace(str[cmpt]) == 0 && str[cmpt])
				cmpt++;
			x_cmpt++;
		}
		x_cmpt = 0;
		y_cmpt++;
	}
}
