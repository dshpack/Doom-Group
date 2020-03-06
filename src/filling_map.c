/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <dshpack@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 20:14:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/06/17 20:14:00 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void		calc_yxy(int *y, int *w, int *h, t_sect *s)
{
	*y = CALC_Y(SF.first.y) - 1;
	*w = CALC_X(SF.second.x);
	*h = CALC_Y(SF.third.y);
}

void		fill_up_by_trgnl_l(t_map *map, t_sect *s)
{
	int		x;
	int		y;
	int		w;
	int		h;

	calc_yxy(&y, &w, &h, s);
	while (++y <= h)
	{
		x = CALC_X(SF.first.x) - 1;
		while (++x <= w)
		{
			if ((x == w || x == CALC_X(SF.first.x) || y == CALC_Y(SF.first.y))
				&& (map->dot[y][x].status == 0 || map->dot[y][x].status == 4))
				map->dot[y][x].status = 4;
			else
				map->dot[y][x].status = TRUE;
			if (x < w && y < h)
				map_dot(map, s, x, y);
		}
		w--;
	}
}

void		fill_up_by_trgnl_r(t_map *map, t_sect *s)
{
	int		x;
	int		y;
	int		w;
	int		h;
	int		offset;

	calc_yxy(&y, &w, &h, s);
	offset = 0;
	while (++y <= h)
	{
		x = CALC_X(SF.first.x) - 1 + offset;
		while (++x <= w)
		{
			if ((x == CALC_X(SF.first.x) + offset
				|| y == CALC_Y(SF.first.y) || x == w)
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

void		fill_up_by_rect(t_map *map, t_sect *s)
{
	int		x;
	int		y;
	int		w;
	int		h;

	y = CALC_Y(SF.first.y) - 1;
	w = CALC_X(SF.fourth.x);
	h = CALC_Y(SF.fourth.y);
	while (++y <= h)
	{
		x = CALC_X(SF.first.x) - 1;
		while (++x <= w)
		{
			if ((x == CALC_X(SF.first.x) || x == w
				|| y == CALC_Y(SF.first.y) || y == h)
				&& (map->dot[y][x].status == 0 || map->dot[y][x].status == 4))
				map->dot[y][x].status = 4;
			else
				map->dot[y][x].status = TRUE;
			if (x < w && y < h)
				map_dot(map, s, x, y);
		}
	}
}

void		fill_up_map_cells(t_map *map, t_sect *s)
{
	if (s->type == RECTANGLE)
		fill_up_by_rect(map, s);
	else if (s->type == TRIANGLE_DOWN_R)
		fill_up_by_trgnl_d_r(map, s);
	else if (s->type == TRIANGLE_DOWN_L)
		fill_up_by_trgnl_d_l(map, s);
	else if (s->type == TRIANGLE_UP_L)
		fill_up_by_trgnl_l(map, s);
	else if (s->type == TRIANGLE_UP_R)
		fill_up_by_trgnl_r(map, s);
}
