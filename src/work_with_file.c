/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:07:26 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/25 14:07:27 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"
#include "../include/get_next_line.h"

void	read_file(t_system *sys)
{
	char	*line;
	int32_t	fd;
	t_list	*list;

	list = NULL;
	if ((fd = open(sys->map, O_RDONLY)) < 0)
		print_error("Error, bad file");
	while (get_next_line(fd, &line))
	{
		tmp_list(&list, (void *)line, ft_strlen(line));
		ft_strdel(&line);
	}
	ft_strdel(&line);
	parse_all(sys, list);
}

void	parse_all(t_system *sys, t_list *list)
{
	parse_vertex(sys, list);
	parse_sec(sys, list);
	parse_player(sys, list);
	sys->sectors->ver_arr_len = 0;
	sys->sum_vert = 0;
	sys->sum_vert_pair = 0;
	free_tmp_list(&list);
}

void	print_error(const char *msg)
{
	ft_putendl(msg);
	exit(0);
}

void	tmp_list(t_list **lst, const void *content,
		const size_t content_size)
{
	t_list	*tmp;

	if (!*lst)
		*lst = ft_lstnew(content, content_size);
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew(content, content_size);
	}
}

void	free_tmp_list(t_list **head)
{
	t_list	*tmp;

	while (*head)
	{
		tmp = *head;
		ft_memdel(&tmp->content);
		ft_memdel((void *)&tmp);
		(*head) = (*head)->next;
	}
	ft_memdel((void **)head);
}
