/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <pcalime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 04:27:24 by pcalime           #+#    #+#             */
/*   Updated: 2016/06/25 02:13:16 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opts	*init_options()
{
	t_opts	*ret;

	ret = ft_memalloc(sizeof(t_opts));
	ret->a = 0;
	ret->r = 0;
	ret->big_r = 0;
	ret->l = 0;
	ret->t = 0;
	return (ret);
}

void	affiche_dir(char *str, t_opts *options, int mult_dir)
{
	t_list			*begin_list;
	DIR				*directory;
	struct dirent	*str_dir;
	t_print			siz_prt;

	begin_list = NULL;
	directory = opendir(str);
	init_t_print(&siz_prt);
	if (mult_dir != 0)
	{
		ft_putstr(str);
		ft_putstr(":\n");
	}
	while ((str_dir = readdir(directory)) != NULL)
	{
		if (options->a == 0 && str_dir->d_name[0] == '.')
			mult_dir = mult_dir + 1 - 1;
		else
			max_t_print(&siz_prt, sort_list(&begin_list, str_dir->d_name, str));
	}
	if (options->t == 1)
		sort_time(&begin_list);
	if (options->r == 1)
		reverse_list(&begin_list);
	if (options->l == 1 && begin_list != NULL)
		affiche_total(siz_prt);
	while (begin_list != NULL)
	{
		if (options->l == 1)
			affiche_l(begin_list->file_stat, begin_list->name, siz_prt);
		else
		{
			ft_putstr(begin_list->name);
			ft_putchar('\n');
		}
		begin_list = begin_list->next;
	}
}

void	ft_ls1()
{
	t_list			*begin_list;
	DIR				*directory;
	struct dirent	*str_dir;

	begin_list = NULL;
	if ((directory = opendir(".")) == NULL)
	{
		perror("error ");
		exit(-1);
	}
	while ((str_dir = readdir(directory)) != NULL)
	{
		if (str_dir->d_name[0] != '.')
			sort_list(&begin_list, str_dir->d_name, ".");
	}
	while (begin_list != NULL)
	{
		ft_putstr(begin_list->name);
		ft_putchar('\n');
		begin_list = begin_list->next;
	}
}

void	ft_ls2(int argc, char **argv)
{
	t_opts		*options;
	struct stat	file_stat;
	int			cmpt;
	t_print		siz_prt;
	int			mult_dir;

	init_t_print(&siz_prt);
	cmpt = 1;
	options = init_options();
	if (argv[1][0] == '-')
	{
		ft_parse_opt(argv[1], options);
		cmpt++;
	}
	mult_dir = cmpt + 1 - argc;
	if (argc == 2)
	{
		affiche_dir(".", options, 0);
		return ;
	}
	sort_arg(argc, argv, cmpt, options);
	while (cmpt < argc)	//la mettre dans sort_arg comme sa je fais tout dirctement
	{
		lstat (argv[cmpt], &file_stat);
		if (S_ISDIR(file_stat.st_mode))
		{
			affiche_dir(argv[cmpt], options, mult_dir);
		}
		else
		{
			siz_prt = fill_print(file_stat);
			if (options->l == 1)
				affiche_l(file_stat, argv[cmpt], siz_prt);
		}
		cmpt++;
		if (cmpt < argc)
			ft_putchar('\n');
	}
}


/*
argc = 1
liste sans options du dossier present

argc = 2
sois argv[1] = options -> liste avec options du dossier present;
sois argv[1] = dossier -> liste sans options du dossier en paramatre; warning fichier

argc >= 3
sois argv[1] = options -> liste du dossier en parametre (argv[2] (ou plus)) avec les options
sois argv[1] = dossier -> liste des n dossier sans parametre;
*/


void	ft_parse_opt(char *str, t_opts *options)
{
	int		cmpt;

	cmpt = 0;
	if (str[1] == '\0')
	{
		ft_putstr("error");
		exit(0);
	}
	while (str[++cmpt])
	{
		if (str[cmpt] == 'a')
			options->a = 1;
		else if (str[cmpt] == 'r')
			options->r = 1;
		else if (str[cmpt] == 'R')
			options->big_r = 1;
		else if (str[cmpt] == 'l')
			options->l = 1;
		else if (str[cmpt] == 't')
			options->t = 1;
		else
		{
			ft_putstr("error");
			exit(0);
		}
	}
}
