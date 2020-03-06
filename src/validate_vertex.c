/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_vertex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:05:56 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/25 14:05:57 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

t_bool		validate_vertex(char *vertex_data)
{
	char	*data;
	size_t	vertex_len;

	vertex_len = ft_strlen("vertex");
	if (!ft_strequ(vertex_data, "vertex"))
	{
		data = vertex_data + vertex_len;
		if (!validate_dilims(data) || !validate_coords(data))
			print_error("Error, bad vertex validation");
	}
	else
		print_error("Error, bad vertex");
	return (true);
}

t_bool		validate_dilims(char *vertex_data)
{
	char	*tmp;
	size_t	num;

	num = 0;
	tmp = vertex_data;
	while (ft_strchr(tmp, '\t'))
	{
		tmp = ft_strchr(tmp, '\t') + 1;
		num++;
	}
	if (num < 2 || num > 2)
		return (false);
	return (true);
}

t_bool		validate_coords(char *vertex_data)
{
	size_t	c;
	size_t	num;

	num = 0;
	c = 0;
	while (vertex_data[c])
	{
		if (vertex_data[c] != '\t' && vertex_data[c] != ' ')
		{
			if (!ft_isdigit(vertex_data[c]) || !validate_num(&vertex_data[c]))
				return (false);
			else
			{
				num++;
				while (vertex_data[c] && (ft_isdigit(vertex_data[c])
					|| vertex_data[c] == '.'))
					c++;
				continue ;
			}
		}
		c++;
	}
	if (num < 2)
		return (false);
	return (true);
}

t_bool		validate_num(char *vertex_data)
{
	t_bool	res;
	size_t	size;
	char	*buff;

	size = 0;
	while (ft_isdigit(vertex_data[size]))
		size++;
	buff = ft_strndup(vertex_data, size);
	res = ft_isint(buff, true);
	ft_strdel(&buff);
	return (res);
}

double		*allocate_vertex_x_array(size_t size)
{
	double *array;

	if (!(array = (double *)ft_memalloc(sizeof(double) * size)))
		print_error("Error, Can't allocate memory region");
	return (array);
}
