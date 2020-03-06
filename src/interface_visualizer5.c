/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_visualizer5.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <dshpack@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:45:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/05/22 18:45:00 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

int			is_place_occupied_for_trngl_d_r(t_sect *s, t_map map)
{
	int		x;
	int		y;
	int		w;
	int		h;

	y = CALC_Y(s->figure.second.y) + 1;
	w = CALC_X(s->figure.third.x);
	h = CALC_Y(s->figure.first.y);
	while (--y >= h)
	{
		x = CALC_X(s->figure.first.x) + 1;
		while (--x >= w)
		{
			if (map.dot[y][x].status == 1)
				return (TRUE);
		}
		w++;
	}
	return (FALSE);
}

int			is_place_occupied_for_trngl_d_l(t_sect *s, t_map map)
{
	int		x;
	int		y;
	int		w;
	int		h;

	y = CALC_Y(s->figure.first.y) - 1;
	w = CALC_X(s->figure.second.x);
	h = CALC_Y(s->figure.third.y);
	while (++y <= h)
	{
		x = CALC_X(s->figure.first.x) - 1;
		while (++x <= w)
		{
			if (map.dot[y][x].status == 1)
				return (TRUE);
		}
	}
	return (FALSE);
}

int			is_place_occupied_for_trngl_r(t_sect *s, t_map map)
{
	int		x;
	int		y;
	int		w;
	int		h;
	int		offset;

	y = CALC_Y(s->figure.first.y) - 1;
	w = CALC_X(s->figure.second.x);
	h = CALC_Y(s->figure.third.y);
	offset = 0;
	while (++y <= h)
	{
		x = CALC_X(s->figure.first.x) - 1 + offset;
		while (++x <= w)
		{
			if (map.dot[y][x].status == 1)
				return (TRUE);
		}
		offset++;
	}
	return (FALSE);
}

int			is_place_occupied_for_trngl_l(t_sect *s, t_map map)
{
	int		x;
	int		y;
	int		w;
	int		h;

	y = CALC_Y(s->figure.first.y) - 1;
	w = CALC_X(s->figure.second.x);
	h = CALC_Y(s->figure.third.y);
	while (++y <= h)
	{
		x = CALC_X(s->figure.first.x) - 1;
		while (++x <= w)
		{
			if (map.dot[y][x].status == 1)
				return (TRUE);
		}
		w--;
	}
	return (FALSE);
}

int			is_place_occupied(t_sect *s, t_map map)
{
	int		x;
	int		y;
	int		w;
	int		h;

	if (s->type == TRIANGLE_DOWN_R)
		return (is_place_occupied_for_trngl_d_r(s, map));
	else if (s->type == TRIANGLE_DOWN_L)
		return (is_place_occupied_for_trngl_d_l(s, map));
	else if (s->type == TRIANGLE_UP_L)
		return (is_place_occupied_for_trngl_l(s, map));
	else if (s->type == TRIANGLE_UP_R)
		return (is_place_occupied_for_trngl_r(s, map));
	y = CALC_Y(s->figure.first.y) - 1;
	w = CALC_X(s->figure.fourth.x);
	h = CALC_Y(s->figure.fourth.y);
	while (++y <= h)
	{
		x = CALC_X(s->figure.first.x) - 1;
		while (++x <= w)
			if (map.dot[y][x].status == 1)
				return (TRUE);
	}
	return (FALSE);
}
