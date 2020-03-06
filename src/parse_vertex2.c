/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vertex2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:05:30 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/25 14:05:31 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

float			parse_ver_y(char *vertex_line)
{
	char	*s1;
	float	num;

	s1 = ft_strchr(vertex_line, '\t') + 1;
	num = ft_atoi(s1);
	return (num);
}

double			*parse_ver_x(char *vertex_line, size_t *size_arr)
{
	char		**tmp;
	double		*array;
	size_t		size;
	size_t		count;

	count = 0;
	tmp = ft_strsplit(find_x_values(vertex_line), ' ');
	size = two_len(tmp);
	array = allocate_vertex_x_array(size);
	while (count < size)
	{
		array[count] = ft_atoi(tmp[count]);
		count++;
	}
	*size_arr = size;
	two_del(&tmp);
	return (array);
}

char			*find_x_values(char *vertex_line)
{
	char		*tmp;

	tmp = vertex_line;
	while (ft_strchr(tmp, '\t'))
		tmp = ft_strchr(tmp, '\t') + 1;
	return (tmp);
}

size_t			two_len(char **array)
{
	size_t		size;

	size = 0;
	while (array[size])
		size++;
	return (size);
}

void			two_del(char ***array)
{
	char		**buff;

	buff = *array;
	while (*buff)
	{
		ft_strdel(&(*buff));
		buff++;
	}
	free(*array);
	*array = NULL;
}
