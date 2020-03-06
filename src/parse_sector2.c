/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sector2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:59:45 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/25 13:59:46 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

t_sector		parse_height_params(char *data)
{
	t_sector	height;
	char		**tmp;

	ft_bzero(&height, sizeof(t_sector));
	if (data)
	{
		tmp = ft_strsplit(data, ' ');
		if (two_len(tmp) == 2 && !int_error(tmp))
		{
			height.floor = ft_atoi(tmp[M1(1)]);
			height.ceil = ft_atoi(tmp[M1(2)]);
		}
		else
			print_error("Error, wrong sector height param");
		two_del(&tmp);
	}
	return (height);
}

t_xy			*parse_vertex_pair(t_system *sys, char **data, size_t size)
{
	t_xy		*vertex_array;
	int32_t		val;
	size_t		i;
	size_t		j;
	struct s_xy	*tmp;

	j = 0;
	i = 0;
	vertex_array = (t_xy *)ft_memalloc((size + 1) * sizeof(t_xy));
	while (++i <= size)
	{
		val = ft_atoi(data[j]);
		if (ABS(val) < (int)sys->sum_vert_pair)
		{
			tmp = search_vertex_pair(sys, val);
			vertex_array[i] = (*tmp);
			free(tmp);
			if (i == size)
				vertex_array[0] = vertex_array[i];
		}
		else
			print_error("Error, no vertex pair");
		j++;
	}
	return (vertex_array);
}

t_xy			*search_vertex_pair(t_system *sys, int32_t pair)
{
	t_xy		*vertex_pair;
	size_t		i;
	size_t		j;

	i = 0;
	vertex_pair = (t_xy*)allocate_vertex_pair();
	while (i <= sys->sum_vert)
	{
		j = 0;
		while (j < sys->vertex[i].x_arr_size)
		{
			if (pair == 0)
			{
				vertex_pair->y = sys->vertex[i].y;
				vertex_pair->x = sys->vertex[i].x_arr[j];
				return (vertex_pair);
			}
			pair--;
			j++;
		}
		i++;
	}
	return (NULL);
}

double			*allocate_vertex_pair(void)
{
	double		*vertex;

	if (!(vertex = (double *)ft_memalloc(sizeof(double) * 2)))
		print_error("Error, can't allocate memory region");
	return (vertex);
}
