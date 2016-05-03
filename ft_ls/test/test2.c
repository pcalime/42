/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 22:47:15 by pcalime           #+#    #+#             */
/*   Updated: 2016/05/02 22:47:19 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <libft.h>
#include <dirent.h>
#include <string.h>

typedef struct		s_list
{
	char			*name;
	struct s_list	*next;
}					t_list;

t_list *create_new_elem(void)
{
	t_list *new_elem;

	new_elem = ft_memalloc(sizeof(t_list));
	new_elem->next = NULL;
	return (new_elem);
}

void	sort_list(t_list **begin_list, struct dirent *str_dir)
{
	t_list	*new_elem;
	t_list	*tmp;
	t_list	*tmp2;

	new_elem = create_new_elem();
	new_elem->name = str_dir->d_name;
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
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
		{
			tmp->next = new_elem;
			return ;
		}
		else if (strcmp(tmp->next->name, str_dir->d_name) > 0)
		{
			tmp2 = tmp->next;
			tmp->next = new_elem;
			new_elem->next = tmp2;
			return ;
		}
		tmp = tmp->next;
	}
}

int		main(int argc, char **argv)
{
	DIR				*directory;
	struct dirent	*str_dir;
	t_list			*begin_list;

	if(argc != 2)
		return (1);
	begin_list = NULL;
	directory = opendir(argv[1]);
	while ((str_dir = readdir(directory)) != NULL)
	{
		sort_list(&begin_list, str_dir);
	}
	while (begin_list != NULL)
	{
		ft_putstr(begin_list->name);
		write(1, "\n", 1);
		begin_list = begin_list->next;
	}
	closedir(directory);
	return (0);
}
