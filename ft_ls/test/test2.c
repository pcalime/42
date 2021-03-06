/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <pcalime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 22:47:15 by pcalime           #+#    #+#             */
/*   Updated: 2016/06/20 23:31:17 by pcalime          ###   ########.fr       */
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

static void	ft_kind_file(struct stat file_stat)
{
	if (S_ISDIR(file_stat.st_mode))
		ft_putchar('d');
	else if (S_ISREG(file_stat.st_mode))
		ft_putchar('-');
	else if (S_ISLNK(file_stat.st_mode))
		ft_putchar('l');
	else if (S_ISCHR(file_stat.st_mode))
		ft_putchar('c');
	else if (S_ISBLK(file_stat.st_mode))
		ft_putchar('b');
	else if (S_ISFIFO(file_stat.st_mode))
		ft_putchar('p');
	else
		ft_putchar('s');
}

void	ft_affiche_modes(struct stat file_stat)
{
	ft_kind_file(file_stat);
	ft_putchar((file_stat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((file_stat.st_mode & S_IWUSR) ? 'w' : '-');
	if ((file_stat.st_mode & S_ISUID) && (file_stat.st_mode & S_IXUSR))
		ft_putstr("s");
	else if (file_stat.st_mode & S_ISUID)
		ft_putstr("S");
	else
		ft_putchar((file_stat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((file_stat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((file_stat.st_mode & S_IWGRP) ? 'w' : '-');
	if ((file_stat.st_mode & S_ISGID) && (file_stat.st_mode & S_IXGRP))
		ft_putstr("s");
	else if (file_stat.st_mode & S_ISGID)
		ft_putstr("S");
	else
		ft_putchar((file_stat.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((file_stat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((file_stat.st_mode & S_IWOTH) ? 'w' : '-');
	if ((file_stat.st_mode & S_ISVTX) && (file_stat.st_mode & S_IXOTH))
		ft_putstr("t");
	else if (file_stat.st_mode & S_ISVTX)
		ft_putstr("T");
	else
		ft_putchar((file_stat.st_mode & S_IXOTH) ? 'x' : '-');
}


void	ft_putnstr(char *str, int n)
{
	int		cmpt;

	if (n > 0)
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
	int		tmp;

	if (n > 0)
	{
		tmp = size_of_int(nbr);
		while (--n >= tmp)
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
	ft_putchar(' ');
	ft_putstr(&aff[4]);
}

void	affiche_l(struct stat file_stat, char *name, t_print size_print)
{
	char	buf2[1024];
	char	buf1[1024];

	ft_bzero(buf2, sizeof(buf2));
	ft_bzero(buf1, sizeof(buf1));


	ft_affiche_modes(file_stat);
	ft_putnnbr(file_stat.st_nlink, (size_print.links + 1));
	ft_putchar(' ');
	if (getpwuid(file_stat.st_uid)->pw_name != NULL)
		ft_putnstr(getpwuid(file_stat.st_uid)->pw_name, -size_print.user - 3);
	if (getgrgid(file_stat.st_gid)->gr_name != NULL)
		ft_putnstr(getgrgid(file_stat.st_gid)->gr_name, -size_print.groupe - 1);
	ft_putnnbr(file_stat.st_size, size_print.size + 1);
	cut_time(file_stat.st_mtime);
	ft_putchar(' ');
	ft_putnstr(name, -2);

// CREER UNE AUTRE FONCTION APRES AFFICHE_L

/*
	if (S_ISLNK(file_stat.st_mode))
	{
		ft_putstr(" -> ");
		getcwd(buf1, 1023);
		//ft_putstr(buf1);
		readlink("/tmp", buf2, 1023);
		write(1, buf2, 1024);//ft_strlen(buf2));
		//si c est un  lien symbolique ecrire le lien;
	}
	*/
////////////////////////////////////////////////////////
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
	max->total += new.total;
}

void	init_t_print(t_print *ini)
{
	ini->links = 0;
	ini->user = 0;
	ini->groupe = 0;
	ini->size = 0;
	ini->link_space = 0;
	ini->total = 0;
}

void	affiche_total(t_print siz_prt)
{
	ft_putstr("total ");
	ft_putnbr(siz_prt.total);
	ft_putchar('\n');
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
								//A FAIRE !!!
/* 	-R (faut le faire)!!!!!!
	le parsing (ca a l aire plutot bon)(quand y a des dossier et fichier les mettre separement)
	liens symboliques -l (affiche_l faut rajouter le lien(trouver le path complet))
	gestion d erreur

*//////////////////////////////////////////////////////////////////////////////////////////////////////

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_ls1();
	else
		ft_ls2(argc, argv);
	return (0);
}

/*
int		main(int argc, char **argv)
{
	t_opts	*options;
	t_list	*begin_list;
	DIR		*directory;
	struct dirent	*str_dir;
	t_print	siz_prt;

	init_t_print(&siz_prt);
	options = init_options();
	if (argc == 1)
		ft_ls1();
	if (argc == 3)
	{
		ft_parse_opt(argv[1], options);
		if ((directory = opendir(argv[2])) == NULL)
		{
			perror("error ");
			return (-1);
		}
		while ((str_dir = readdir(directory)) != NULL)
		{
			if (options->a == 0 && str_dir->d_name[0] == '.')
				argc = 3;
			else
				max_t_print(&siz_prt, sort_list(&begin_list, str_dir, argv[2]));
		//	printf("max  : %d\n", siz_prt.links);
		}
		//printf("%d %d %d %d\n", siz_prt.links, siz_prt.user, siz_prt.groupe, siz_prt.size);
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
				write(1, "\n", 1);
			}
			begin_list = begin_list->next;
		}
	}
	return (0);
}*/
