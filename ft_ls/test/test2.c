/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <pcalime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 22:47:15 by pcalime           #+#    #+#             */
/*   Updated: 2016/05/08 05:38:33 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list			*create_new_elem(void)
{
	t_list *new_elem;

	new_elem = ft_memalloc(sizeof(t_list));
	new_elem->next = NULL;
	return (new_elem);
}

void	ft_affiche_modes(struct stat file_stat)
{
	ft_putchar((S_ISDIR(file_stat.st_mode)) ? 'd' : '-');
	if (file_stat.st_mode & S_ISVTX)
		ft_putstr("--------T");
	else if (file_stat.st_mode & S_ISGID)
		ft_putstr("-----S---");
	else if (file_stat.st_mode & S_ISUID)
		ft_putstr("--S------");
	else
	{
		ft_putchar((file_stat.st_mode & S_IRUSR) ? 'r' : '-');
		ft_putchar((file_stat.st_mode & S_IWUSR) ? 'w' : '-');
		ft_putchar((file_stat.st_mode & S_IXUSR) ? 'x' : '-');
		ft_putchar((file_stat.st_mode & S_IRGRP) ? 'r' : '-');
		ft_putchar((file_stat.st_mode & S_IWGRP) ? 'w' : '-');
		ft_putchar((file_stat.st_mode & S_IXGRP) ? 'x' : '-');
		ft_putchar((file_stat.st_mode & S_IROTH) ? 'r' : '-');
		ft_putchar((file_stat.st_mode & S_IWOTH) ? 'w' : '-');
		ft_putchar((file_stat.st_mode & S_IXOTH) ? 'x' : '-');
	}
}


void	ft_putnstr(char *str, int n)
{
	int		cmpt;

	if(n > 0)
	{
		cmpt = ft_strlen(str);
		while (++cmpt < n)
			ft_putchar(' ');
	}
	cmpt = ft_strlen(str);
	ft_putstr(str);
	if (n < 0)
	{
		n = -n;
		while (++cmpt < n)
			ft_putchar(' ');
	}
}

void	ft_putnnbr(int nbr, int n)
{
	int		cmpt;
	int		tmp;

	if (n > 0)
	{
		cmpt = 0;
		tmp = nbr;
		while (tmp > 10)
		{
			cmpt++;
			tmp /= 10;
		}
		while (++cmpt < n)
			ft_putchar(' ');
	}
	else
	{
		while (++n <= 0)
			ft_putchar(' ');
	}
	ft_putnbr(nbr);
}

void	cut_time(time_t time_f)
{
	struct tm	*time_struct;
	char		*aff;

	time_struct = localtime(&time_f);
	aff = ctime(&time_f);
	if (time_struct->tm_year == 116)
		aff[16] = '\0';
	else
	{
		aff[10] = '\0';
		aff[18] = ' ';
		ft_strcat(aff, &aff[18]);
		aff[16] = '\0';
	}
	ft_putnstr(&aff[4], -1);
}

void	affiche_l(struct stat file_stat, char *name, t_print size_print)
{
	printf("\n%d\n%d\n%d\n%d\n", size_print.links, size_print.user, size_print.groupe, size_print.size);
	ft_affiche_modes(file_stat);
	ft_putnnbr(file_stat.st_nlink, (size_print.links + 4));
	if (getpwuid(file_stat.st_uid)->pw_name != NULL)
		ft_putnstr(getpwuid(file_stat.st_uid)->pw_name, -size_print.user - 2);
	if (getgrgid(file_stat.st_gid)->gr_name != NULL)
		ft_putnstr(getgrgid(file_stat.st_gid)->gr_name, -size_print.groupe - 1);
	ft_putnnbr(file_stat.st_size, size_print.size + 1);
	cut_time(file_stat.st_mtime);
	ft_putnstr(name, -1);
	ft_putchar('\n');
}

void	max_t_print(t_print *max, t_print new)
{
	if (max->links < new.links)
		max->links = new.links;
	if (max->user < new.user)
		max->user = new.user;
	if (max->groupe < new.groupe)
		max->groupe = new.groupe;
	if (max->size < new.size)
		max->size = new.size;
}

int		main(int argc, char **argv)
{
	t_opts	*options;
	t_list	*begin_list;
	DIR		*directory;
	struct dirent	*str_dir;
	t_print	siz_prt;

	options = init_options();
	if (argc == 3)
	{
		if ((directory = opendir(argv[2])) == NULL)
		{
			perror("error ");
			return (-1);
		}
		while ((str_dir = readdir(directory)) != NULL)
		{
			max_t_print(&siz_prt, sort_list(&begin_list, str_dir, argv[2]));
		}
		printf("\n%d\n%d\n%d\n%d\n", siz_prt.links, siz_prt.user, siz_prt.groupe, siz_prt.size);
		return(0);
		ft_parse_opt(argv[1], options);
//		if (options->t == 1)
//			sort_list_t;
//		if (options->r == 1)
//			reverse_list;
		while (begin_list != NULL)
		{
			if (options->a == 0 && begin_list->name[0] == '.')
				begin_list = begin_list->next;
			else
			{
				if (options->l == 1)
					affiche_l(begin_list->file_stat, begin_list->name, siz_prt);
				else
				{
					ft_putstr(begin_list->name);
					write(1, "\n", 1);
				}
				begin_list = begin_list->next;
			}
		}
	}
	return (0);
}

/*
int		main(int argc, char **argv)
{
//	DIR				*directory;
//	struct dirent	*str_dir;
	t_list			*begin_list;
	struct stat		file_stat;

	if (argc != 2)
		return (1);
	begin_list = NULL;
	if (lstat(argv[1], &file_stat) == -1)
	{
		perror ("error ");
		return (0);
	}
	affiche_l(file_stat, argv[1]);
	if ((directory = opendir(argv[1])) == NULL)
	{
		perror("error ");
		return (0);
	}
	while ((str_dir = readdir(directory)) != NULL)
	{
		sort_list(&begin_list, str_dir);
	}
	while (begin_list != NULL)			//afficher le dossier.
	{
		ft_putstr(begin_list->name);
		write(1, "\n", 1);
		begin_list = begin_list->next;
	}
	closedir(directory);
	return (0);
}*/
