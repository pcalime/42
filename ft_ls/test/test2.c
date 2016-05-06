/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <pcalime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 22:47:15 by pcalime           #+#    #+#             */
/*   Updated: 2016/05/06 04:57:03 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_affiche_modes(struct stat file_stat)
{
	ft_putchar((S_ISDIR(file_stat.st_mode)) ? 'd' : '-');
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


void	ft_putnstr(char *str, int n)
{
	int		cmpt;

	if(n > 0)
	{
		cmpt = ft_strlen(str);
		while (++cmpt < n)
			ft_putchar(' ');
	}
	else
	{
		while (++n <= 0)
			ft_putchar(' ');
	}
	ft_putstr(str);
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

char	*cut_time(char *time_f)
{
	int		cmpt;
	int		cmpt2;

	cmpt2 = 0;
	cmpt = -1;
	while (time_f[++cmpt])
	{
		if (time_f[cmpt] == ':')
		{
			if (cmpt2 == 1)
			{
				time_f[cmpt] = '\0';
				return (time_f);
			}
			cmpt2++;
		}
	}
	return (time_f);
}

void	affiche_l(struct stat file_stat, char *name)
{
	char	*time_f;

	time_f = cut_time(&ctime(&file_stat.st_mtime)[4]);
	ft_affiche_modes(file_stat);
	ft_putnnbr(file_stat.st_nlink, 3);
	ft_putnstr(getpwuid(file_stat.st_uid)->pw_name, -1);
	ft_putnstr(getgrgid(file_stat.st_gid)->gr_name, -2);
	ft_putnnbr(file_stat.st_size, -2);
	ft_putnstr(time_f, -1);
	ft_putnstr(name, -1);
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
//	DIR				*directory;
//	struct dirent	*str_dir;
	t_list			*begin_list;
	struct stat		file_stat;

	if (argc != 2)
		return (1);
	begin_list = NULL;
	if (stat(argv[1], &file_stat) == -1)
	{
		perror ("error ");
		return (0);
	}
	affiche_l(file_stat, argv[1]);
	/*if ((directory = opendir(argv[1])) == NULL)
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
	closedir(directory);*/
	return (0);
}
