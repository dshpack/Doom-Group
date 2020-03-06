/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:50:25 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/25 13:50:32 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"
#include "math.h"

void			parse_player(t_system *sys, t_list *list)
{
	t_list		*elem;

	elem = find_elem(list, "player");
	if (elem)
		*sys->player = parse_player_parameters((char *)elem->content);
}

void			parse_player_helper(t_player *player, char **tmp)
{
	player->where = define_position(tmp[M1(1)]);
	player->anglesin = sinf(player->angle);
	player->anglecos = cosf(player->angle);
	if (!int_error(&tmp[M1(2)]))
		player->num_sect = ft_atoi(tmp[M1(2)]);
}

t_player		parse_player_parameters(char *data)
{
	char		**tmp;
	t_player	player;

	ft_bzero(&player, sizeof(t_player));
	if (data)
	{
		tmp = ft_strsplit(ft_strchr(data, '\t'), '\t');
		if (two_len(tmp) == 2)
			parse_player_helper(&player, tmp);
		else
			print_error("Error, bad vector position");
		two_del(&tmp);
	}
	return (player);
}

void			pn_helper(t_sector *sector, size_t idx,
	size_t i, int32_t *neighbours)
{
	sector->transit_array[idx].is_wall = neighbours[idx];
	sector->transit_array[idx].start_wall[0] = sector->vertex[i].x;
	sector->transit_array[idx].start_wall[1] = sector->vertex[i].y;
	sector->transit_array[idx].end_wall[0] = sector->vertex[idx].x;
	sector->transit_array[idx].end_wall[1] = sector->vertex[idx].y;
}

int32_t			*parse_neighbours(char *data, t_sector *sector)
{
	int32_t		*neighbours;
	char		**tmp;
	int			i;
	size_t		idx;
	size_t		a;

	a = sector->ver_arr_len;
	i = -1;
	tmp = ft_strsplit(data, ' ');
	neighbours = ft_memalloc(sizeof(int32_t) * sector->ver_arr_len);
	sector->transit_array = ft_memalloc(sizeof(t_wall) * (a + 1));
	while (tmp[++i])
		neighbours[i] = ft_atoi(tmp[i]);
	while (i--)
	{
		idx = (i + 1) % sector->ver_arr_len;
		pn_helper(sector, idx, i, neighbours);
	}
	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
	return (neighbours);
}
