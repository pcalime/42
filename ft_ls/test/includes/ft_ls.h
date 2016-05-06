/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <pcalime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 23:42:19 by pcalime           #+#    #+#             */
/*   Updated: 2016/05/06 04:33:16 by pcalime          ###   ########.fr       */
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
}					t_print;

typedef struct		s_list
{
	char			*name;
	struct s_list	*next;
	struct stat		*file_stat;
}					t_list;

typedef struct		s_opts
{
	int				l;
	int				a;
	int				r;
	int				t;
	int				R;
}					t_opts;

void	sort_list(t_list **begin_list, struct dirent *str_dir);
t_list	*create_new_elem(void);

#endif
