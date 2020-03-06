/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <osak@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 03:23:28 by osak              #+#    #+#             */
/*   Updated: 2019/07/01 03:23:32 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void		map_dot(t_map *map, t_sect *s, int x, int y)
{
	map->dot[y][x].sect_num = s->id;
	map->dot[y][x].sect_type = s->type;
}

void		fill_up_by_trgnl_d_l(t_map *map, t_sect *s)
{
	int		x;
	int		y;
	int		w;
	int		h;

	y = CALC_Y(SF.first.y) - 1;
	w = CALC_X(SF.first.x);
	h = CALC_Y(SF.second.y);
	while (++y <= h)
	{
		x = CALC_X(SF.first.x) - 1;
		while (++x <= w)
		{
			if ((x == w || y == h || x == CALC_X(SF.first.x))
				&& (map->dot[y][x].status == 0 || map->dot[y][x].status == 4))
				map->dot[y][x].status = 4;
			else
				map->dot[y][x].status = TRUE;
			if (x < w && y < h)
				map_dot(map, s, x, y);
		}
		w++;
	}
}

void		fill_up_by_trgnl_d_r(t_map *map, t_sect *s)
{
	int		x;
	int		y;
	int		w;
	int		h;
	int		offset;

	y = CALC_Y(SF.first.y) - 1;
	w = CALC_X(SF.second.x);
	h = CALC_Y(SF.third.y);
	offset = 0;
	while (++y <= h)
	{
		x = CALC_X(SF.first.x) - 1 - offset;
		while (++x <= w)
		{
			if ((x == w || y == h || x + offset == w)
				&& (map->dot[y][x].status == 0 || map->dot[y][x].status == 4))
				map->dot[y][x].status = 4;
			else
				map->dot[y][x].status = TRUE;
			if (x < w && y < h)
				map_dot(map, s, x, y);
		}
		offset++;
	}
}
