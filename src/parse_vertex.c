/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vertex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:03:58 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/25 14:04:00 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void			parse_vertex(t_system *sys, t_list *list)
{
	size_t	s_ar;
	t_list	*e;
	size_t	vertex_num;
	size_t	c;

	c = -1;
	s_ar = 0;
	vertex_num = 0;
	e = find_elem(list, "vertex");
	vertex_num = content_len(e, "vertex");
	sys->vertex = allocate_vertex(vertex_num);
	while (e && ++c < vertex_num)
	{
		if (validate_vertex((char *)e->content))
		{
			sys->vertex[c].y = parse_ver_y((char *)e->content);
			sys->vertex[c].x_arr = parse_ver_x((char *)e->content, &s_ar);
			sys->vertex[c].x_arr_size = s_ar;
			sys->sum_vert_pair += s_ar;
			e = e->next;
		}
		else
			print_error("Error, bad vertex validation1.");
	}
	sys->sum_vert = vertex_num;
}

t_list			*find_elem(t_list *list, char *elem)
{
	while (list && !ft_strstr((char *)list->content, elem))
		list = list->next;
	return (list);
}

size_t			content_len(t_list *list, char *content)
{
	size_t len;

	len = 0;
	while (list && ft_strstr((char *)list->content, content))
	{
		len++;
		list = list->next;
	}
	return (len);
}

t_vertex		*allocate_vertex(size_t size)
{
	t_vertex	*vert_arr;

	if (!(vert_arr = (t_vertex *)ft_memalloc(sizeof(t_vertex) * (size))))
		print_error("Error, bad memory region");
	return (vert_arr);
}

t_xy			*pars_ver_par(char *data, t_system *sys, size_t *len)
{
	t_xy	*vertex_array;
	char	**tmp;

	vertex_array = NULL;
	if (data)
	{
		tmp = ft_strsplit(data, ' ');
		if (two_len(tmp) >= 3 && !int_error(tmp))
		{
			*len = two_len(tmp);
			vertex_array = parse_vertex_pair(sys, tmp, *len);
		}
		else
			print_error("Error, sector validation, bad vertex param");
		two_del(&tmp);
	}
	return (vertex_array);
}
