/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 23:40:25 by pcalime           #+#    #+#             */
/*   Updated: 2016/04/14 00:01:48 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <dirent.h>
#include <unistd.h>
#include <string.h>

typedef struct		s_list
{
	char			*name;
	struct s_list	*next;
}					t_list;

void add_list(t_list *prev_list, t_list *new_list)
{
	new_list->next = prev_list->next;
	prev_list->next = new_list;
}

t_list *create_new_elem(void)
{
	t_list *new_elem;

	new_elem = ft_memalloc(sizeof(t_list));
	new_elem->next = NULL;
	return (new_elem);
}

int		list_len(t_list *begin_list)
{
	int		cmpt;
	t_list	*tmp;

	tmp = begin_list;
	cmpt = 0;
	while (tmp != NULL)
	{
		cmpt++;
		tmp = tmp->next;
	}
	return (cmpt);
}

t_list *create_new_list(int size)
{
	t_list *begin_list;
	t_list *tmp;
	t_list *tmp2;

	begin_list = create_new_elem();
	tmp = begin_list;
	while (--size > 0)
	{
		tmp2 = create_new_elem();
		add_list(tmp, tmp2);
		tmp = tmp2;
	}
	return (begin_list);
}

void 	sort_list(t_list *begin_list)
{
	int		cmpt;
	char	**stoke;
	t_list	*tmp;

	cmpt = list_len(begin_list);
	stoke = malloc(sizeof(char *) * cmpt);
	tmp = begin_list;
	while (tmp != NULL)
	{
		cmpt--;
		stoke[cmpt] = tmp->name;
		tmp = tmp->next;
	}
	//trier stoke et rmplir une new_list
}

int		main (int argc, char **argv)
{
	int		a;

	a = 20;
	if (argc != 2)
		return (1);
	DIR *test;
	struct dirent *str_dir;
	t_list *begin_list;
	t_list *tmp;
	t_list *new_tmp;

	begin_list = ft_memalloc(sizeof(t_list));
	test = opendir(argv[1]);

	tmp = begin_list;
	while ((str_dir = readdir(test)) != NULL)
	{
		new_tmp = create_new_elem();
		tmp->name = str_dir->d_name;
		add_list(tmp, new_tmp);
		tmp = tmp->next;
	}
	sort_list(begin_list);
//	ft_putnbr(list_len(begin_list));
	while (begin_list->next != NULL)
	{
		a = strlen(begin_list->name);
		write(1, begin_list->name, a);
		write(1, "\n", 1);
		begin_list = begin_list->next;
	}
	begin_list = create_new_list(4);
//	ft_putnbr(list_len(begin_list));
	closedir(test);
	return (0);
}
