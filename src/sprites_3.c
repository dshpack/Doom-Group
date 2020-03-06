/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <osak@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 03:08:37 by osak              #+#    #+#             */
/*   Updated: 2019/07/01 03:08:40 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

float		interpolate(t_system *sys, float cmprsd_txtr, float sampling_ratio)
{
	if (SDSC.u >= SPR_H)
	{
		SDSC.u = 0;
		cmprsd_txtr = 0;
	}
	else
	{
		cmprsd_txtr += sampling_ratio;
		SDSC.u = (int)cmprsd_txtr;
	}
	return (cmprsd_txtr);
}

void		vline_card(t_system *sys, int x, int tex_num)
{
	int		y;
	int		y1;
	int		y2;
	float	sampling_ratio;
	float	cmprsd_txtr;

	y1 = SDSCS.y1;
	y2 = SDSCS.y2;
	if (y2 > y1)
	{
		sampling_ratio = (float)SPR_H / (float)(abs(y2 - y1));
		if (sampling_ratio < 0.005)
			sampling_ratio = 0.005;
		cmprsd_txtr = 0;
		y = y1;
		while (y <= y2)
		{
			cmprsd_txtr = interpolate(sys, cmprsd_txtr, sampling_ratio);
			if (y >= y1)
				if (y < H && 0 < y)
					set_color(sys, x, y, tex_num);
			y++;
		}
	}
}

void		cmpr(t_system *sys, float *sampling_ratio, float *cmprsd_txtr,
		int *x1)
{
	SDSC.u = 0;
	SDSC.v = 0;
	*sampling_ratio = (float)SPR_H / (float)(abs(SDSC.endx - SDSC.beginx));
	if (*sampling_ratio < 0.005)
		*sampling_ratio = 0.005;
	*cmprsd_txtr = 0;
	*x1 = SDSC.beginx - 1;
}

void		draw_key_sprite(t_system *sys, int key)
{
	int		x1;
	float	sampling_ratio;
	float	cmprsd_txtr;

	cmpr(sys, &sampling_ratio, &cmprsd_txtr, &x1);
	while (++x1 < SDSC.endx)
	{
		cmprsd_txtr += sampling_ratio;
		SDSC.v = (int)cmprsd_txtr;
		if (SDSC.v >= SPR_W || SDSC.v < 0)
		{
			cmprsd_txtr = 0;
			SDSC.v = 0;
		}
		if (x1 < W && x1 > 0)
		{
			if (x1 > SDSC.beginx - 1)
			{
				SDSCS.y1 = (370 + SDSCS.dist * 0.3) - SP->yaw * 160;
				SDSCS.y2 = SDSCS.y1 + (SDSC.endx - SDSC.beginx);
				vline_card(sys, x1, key);
			}
		}
	}
}

void		find_sprite_visual(t_system *sys, float dist)
{
	SDSC.yceil = SDSC.sect->item[SDSCS.item_num].item_ceil - SP->where.z;
	SDSC.yfloor = SDSC.sect->item[SDSCS.item_num].item_floor - SP->where.z;
	yaw_calc(sys);
	SDSC.beginx = SDSC.x1;
	SDSC.endx = SDSC.beginx + 2000 / dist;
	if (SDSC.endx < 0)
		SDSC.endx = 0;
}
