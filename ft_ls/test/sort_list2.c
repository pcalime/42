/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <pcalime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 02:20:42 by pcalime           #+#    #+#             */
/*   Updated: 2016/06/25 02:13:10 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//malloc un char **
//trie par ordre alphabetique puis find et remplir les erreur les non-dossier et mettre le reste(dossier);
static char **sort_arg2(char **argv, int argc)
{
	int		cmpt;
	int		cmpt2;
	char	*swap;

	cmpt = 1;
	if (argv[1][0] == '-')
		cmpt++;
	cmpt2 = cmpt;
	while (cmpt + 1 < argc)
	{
		if (ft_strcmp(argv[cmpt2], argv[cmpt + 1]) > 0)
		{
			swap = argv[cmpt2];
			argv[cmpt2] = argv[cmpt + 1];
			argv[cmpt + 1] = swap;
			cmpt = cmpt2;
		}
		else
			cmpt++;
		if (cmpt + 1 == argc)
		{
			cmpt2++;
			cmpt = cmpt2;
		}
	}
	return (argv);
}

void	check_error(int argc, char **argv)
{
	struct stat	file_stat;
	int			cmpt;

	cmpt = 1;
	if (argv[1][0] == '-')
		cmpt++;
	while (cmpt < argc)
	{
		if (lstat(argv[cmpt], &file_stat) == -1)
		{
			ft_putstr("ft: ");
			perror(argv[cmpt]);
			ft_putchar('\n');
		}
		cmpt++;
	}
}

void	affiche_file(t_list *begin_list, t_opts *options, t_print siz_prt)
{

}

void	check_file(int argc, char **argv, t_opts *options, t_print siz_prt) 
{
	t_list		*begin_list;
	t_list		*new_elem;
	t_list		*tmp;
	int			cmpt;
	struct stat	file_stat;

	cmpt = 1;
	if (argv[1][0] == '-')
		cmpt++;
	begin_list = NULL;
	init_t_print(&siz_prt);
	while (cmpt < argc)
	{
		if (lstat(argv[cmpt], &file_stat) != -1)
		{
			if (S_ISDIR(file_stat.st_mode) == 0) // ajouter le max_t_print
			{
				new_elem = create_new_elem();
				if (begin_list == NULL)
					begin_list = new_elem;
				else
					tmp->next = new_elem;
				new_elem->name = argv[cmpt];
				new_elem->file_stat = file_stat;
				tmp = new_elem;
			}
		}
		cmpt++;
	}
	affiche_file(begin_list, options, siz_prt);
	//afficher avec les options
}

void	sort_arg(int argc, char **argv, int cmpt, t_opts *options)
{
	//struct stat	file_stat;
	char		**argv_sort;
	t_print		siz_prt;

	init_t_print(&siz_prt);
	argv_sort = sort_arg2(argv, argc);
	cmpt = 0;
	check_file(argc, argv, options, siz_prt);
	/*
	struct stat	file_stat;
	int			cmpt2;
	int			cmpt3;
	char 		**argv_sort;

	argv_sort = (char **)ft_memalloc(sizeof(char *) * (argc - cmpt + 1));
	argv_sort = sort_arg2(argv, argc);
	cmpt2 = cmpt;
	cmpt3 = cmpt;
	while (cmpt < argc)
	{
		if (lstat(argv[cmpt], &file_stat) == -1)
		{
			argv_sort[cmpt3] = argv[cmpt];
			cmpt3++;
		}
		cmpt++;
	}
	cmpt = cmpt2;
	while (cmpt < argc)
	{
		if (lstat(argv[cmpt], &file_stat) != -1)
		{
			if (!S_ISDIR(file_stat.st_mode))
			{
				argv_sort[cmpt3] = argv[cmpt];
				cmpt3++;
			}
		}
		cmpt++;
	}
	cmpt = cmpt2;
	while (cmpt < argc)
	{
		if (lstat(argv[cmpt], &file_stat) != -1)
		{
			if (S_ISDIR(file_stat.st_mode))
			{
				argv_sort[cmpt3] = argv[cmpt];
				cmpt3++;
			}
		}
		cmpt++;
	}
	argv = argv_sort;*/
}

void	reverse_list(t_list **begin_list)
{
	t_list *current;
	t_list *previous;
	t_list *tmp;

	current = *begin_list;
	previous = NULL;
	while (current != NULL)
	{
		tmp = previous;
		previous = current;
		current = current->next;
		previous->next = tmp;
	}
	*begin_list = previous;
}

void	sort_time2(t_list *tmp_beg, t_list *new_beg_list)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = new_beg_list;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
		{
			tmp->next = tmp_beg;
			return ;
		}
		if (tmp->next->file_stat.st_mtime < tmp_beg->file_stat.st_mtime)
		{
			tmp2 = tmp->next;
			tmp->next = tmp_beg;
			tmp_beg->next = tmp2;
			return ;
		}
		tmp = tmp->next;
	}
}

void	sort_time(t_list **begin_list)
{
	t_list	*new_beg_list;
	t_list	*tmp_beg;
	t_list	*tmp;
	t_list	*new_elem;

	tmp_beg = *begin_list;
	while (tmp_beg != NULL)
	{
		new_elem = create_new_elem();
		new_elem->name = tmp_beg->name;
		new_elem->file_stat = tmp_beg->file_stat;
		if (new_beg_list == NULL)
		{
			new_beg_list = new_elem;
			new_beg_list->next = NULL;
		}
		else
		{
			if (new_elem->file_stat.st_mtime > new_beg_list->file_stat.st_mtime)
			{
				tmp = new_beg_list;
				new_beg_list = new_elem;
				new_beg_list->next = tmp;
			}
			else
				sort_time2(new_elem, new_beg_list);
		}
		tmp_beg = tmp_beg->next;
	}
	*begin_list = new_beg_list;
}
