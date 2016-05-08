/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <pcalime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 03:19:16 by pcalime           #+#    #+#             */
/*   Updated: 2016/05/08 05:38:34 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		size_of_int(int nbr)
{
	int		ret;

	ret = 0;
	while (nbr > 10)
	{
		nbr /=10;
		ret++;
	}
	return (ret);
}

static char		*ft_join(char *str1, char *str2)
{
	char	*ret;
	int		cmpt;
	int		cmpt2;

	cmpt2 = -1;
	cmpt = -1;
	ret = ft_memalloc(ft_strlen(str1) + ft_strlen(str2) + 2);
	while (str1[++cmpt])
		ret[cmpt] = str1[cmpt];
	ret[cmpt] = '/';
	while (str2[++cmpt2])
	{
		cmpt++;
		ret[cmpt] = str2[cmpt2];
	}
	return (ret);
}

static t_print	fill_print(struct stat file_stat)
{
	t_print	ret;

	if (file_stat.st_nlink)
		ret.links = size_of_int((int)file_stat.st_nlink);
	if (ft_strlen(getpwuid(file_stat.st_uid)->pw_name) <= 0)
		ret.user = ft_strlen(getpwuid(file_stat.st_uid)->pw_name);
	if (ret.user == 32767)
		ret.user = 0;
	ret.groupe = ft_strlen(getgrgid(file_stat.st_gid)->gr_name);
	ret.size = size_of_int(file_stat.st_size);
	return (ret);
}

static void		sort_list2(t_list *tmp, t_list *new_ele, struct dirent *str_dir)
{
	t_list	*tmp2;

	while (tmp != NULL)
	{
		if (tmp->next == NULL)
		{
			tmp->next = new_ele;
			return ;
		}
		else if (strcmp(tmp->next->name, str_dir->d_name) > 0)
		{
			tmp2 = tmp->next;
			tmp->next = new_ele;
			new_ele->next = tmp2;
			return ;
		}
		tmp = tmp->next;
	}
}

t_print			sort_list(t_list **beg_list, struct dirent *str_dir, char *prev)
{
	t_list	*new_elem;
	t_list	*tmp;
	t_print	ret;

	new_elem = create_new_elem();
	new_elem->name = str_dir->d_name;
	if (lstat(ft_join(prev, new_elem->name), &new_elem->file_stat) == -1)
	{
		perror("error ");
	}
	else
		ret = fill_print(new_elem->file_stat);
	if (*beg_list == NULL)
	{
		*beg_list = new_elem;
		return (ret);
	}
	tmp = *beg_list;
	if (strcmp(tmp->name, str_dir->d_name) > 0)
	{
		*beg_list = new_elem;
		new_elem->next = tmp;
		return (ret);
	}
	sort_list2(tmp, new_elem, str_dir);
	return (ret);
}
