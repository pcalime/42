/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <pcalime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 23:42:19 by pcalime           #+#    #+#             */
/*   Updated: 2016/06/25 02:12:56 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

typedef struct		s_print
{
	int				links;
	int				user;
	int				groupe;
	int				size;
	int				link_space;
	long long		total;
}					t_print;

typedef struct		s_list
{
	char			*name;
	struct s_list	*next;
	struct stat		file_stat;
}					t_list;

typedef struct		s_opts
{
	int				l;
	int				a;
	int				r;
	int				t;
	int				big_r;
}					t_opts;

void	init_t_print(t_print *ini);
void	sort_arg(int argc, char **argv, int cmpt, t_opts *options);
void	ft_ls1();
void	ft_ls2(int argc, char **argv);
t_opts	*init_options();
void	ft_parse_opt(char *str, t_opts *options);
t_print	sort_list(t_list **begin_list, char *name_dir /*struct dirent *str_dir*/, char *previous);
t_list	*create_new_elem(void);
int		size_of_int(int nbr);
void	reverse_list(t_list **begin_list);
void	sort_time(t_list **begin_list);
void	affiche_l(struct stat file_stat, char *name, t_print size_print);
void	affiche_total(t_print siz_prt);
void	max_t_print(t_print *max, t_print new);
t_print	fill_print(struct stat file_stat);

#endif
