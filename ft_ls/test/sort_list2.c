/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <pcalime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 02:20:42 by pcalime           #+#    #+#             */
/*   Updated: 2016/05/17 06:01:36 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_arg(int argc, char **argv, int cmpt) // a faire
{
	char	**ret;

	while (cmpt < argc)
	{
		ret = argv;
		cmpt++;
	}
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
