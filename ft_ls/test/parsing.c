/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <pcalime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 04:27:24 by pcalime           #+#    #+#             */
/*   Updated: 2016/05/06 05:15:08 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opts	*init_options()
{
	t_opts	*ret;

	ret = ft_memalloc(sizeof(t_opts));
	ret->a = 0;
	ret->r = 0;
	ret->R = 0;
	ret->l = 0;
	ret->t = 0;
	return (ret);
}

void	parsing(int argc, char **argv)
{
	t_opts	*options;

	if (argc == 1)
	//	sort_list
	else if (argc == 2)
	{
		if (argv[1][0] == '-')
			ft_parse_opt(argv[1], options)
		else
			//sort_list path = argv[1]
	}
	else if (argc >= 3)
	{
		if (argv[1][0] == '-')
			ft_parse_opt (argv[2], options)
		else
			// argv[1] sort_list
		//prendre tout les args
	}
}

void	ft_parse_opt(char *str, t_opts *options)
{
	int		cmpt;

	cmpt = 0;
	while (str[++cmpt])
	{
		if (str[cmpt] == 'a')
			options->a = 1;
		else if (str[cmpt] == 'r')
			options->r = 1;
		else if (str[cmpt] == 'R')
			options->R = 1;
		else if (str[cmpt] == 'l')
			options->l = 1;
		else if (str[cmpt] == 't')
			options->t = 1;
		else
			//erreur
	}
}
