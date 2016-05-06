/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <pcalime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 03:19:16 by pcalime           #+#    #+#             */
/*   Updated: 2016/05/06 03:23:40 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	void	sort_list2(t_list *tmp, t_list *new_ele, struct dirent *str_dir)
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

void	sort_list(t_list **begin_list, struct dirent *str_dir)
{
	t_list	*new_elem;
	t_list	*tmp;

	new_elem = create_new_elem();
	new_elem->name = str_dir->d_name;
	lstat(new_elem->name, new_elem->file_stat);
	if (*begin_list == NULL)
	{
		*begin_list = new_elem;
		return ;
	}
	tmp = *begin_list;
	if (strcmp(tmp->name, str_dir->d_name) > 0)
	{
		*begin_list = new_elem;
		new_elem->next = tmp;
		return ;
	}
	sort_list2(tmp, new_elem, str_dir);
}

t_list	*create_new_elem(void)
{
	t_list *new_elem;

	new_elem = ft_memalloc(sizeof(t_list));
	new_elem->next = NULL;
	return (new_elem);
}
