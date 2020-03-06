/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 14:19:57 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/30 14:19:58 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void	before_cycle_helper(t_system *sys)
{
	SDSC.nya_int = scaler_init((t_int_xyz) {SDSC.x1, SDSC.beginx, SDSC.x2},
		SDSC.ny1.a, SDSC.ny2.a);
	SDSC.nyb_int = scaler_init((t_int_xyz) {SDSC.x1, SDSC.beginx, SDSC.x2},
		SDSC.ny1.b, SDSC.ny2.b);
	SDSC.xrw = SDSC.beginx - 1;
}

void	for_cycle_helper(t_system *sys, int y)
{
	SDSC.hei = y < SDSC.cy.a ? SDSC.yceil : SDSC.yfloor;
	SDSC.mapz = (float)((SDSC.hei) * H * VFOV /
		((H / 2 - (y)) - SP->yaw * H * VFOV));
	SDSC.mapx = (float)((SDSC.mapz) * (W / 2 - (SDSC.xrw)) / (W * HFOV));
	SDSC.rtx = (SDSC.mapz) * SP->anglecos + (SDSC.mapx) * SP->anglesin;
	SDSC.rtz = (SDSC.mapz) * SP->anglesin - (SDSC.mapx) * SP->anglecos;
	SDSC.mapx = SDSC.rtx + SP->where.x;
	SDSC.mapz = SDSC.rtz + SP->where.y;
	SDSC.txtx = (unsigned int)(SDSC.mapx * 63);
	SDSC.txtz = (unsigned int)(SDSC.mapz * 63);
}

void	for_cycle(t_system *sys)
{
	int				y;
	t_textureset	*txt;

	y = SDSC.ytop[SDSC.xrw] - 1;
	while (++y <= SDSC.ybottom[SDSC.xrw])
	{
		if (y >= SDSC.cy.a && y <= SDSC.cy.b)
		{
			y = SDSC.cy.b;
			continue;
		}
		for_cycle_helper(sys, y);
		txt = y < SDSC.cy.a ? SDSC.sect->ceiltexture
							: SDSC.sect->floortexture;
		SDSC.pel = txt->texture[SDSC.txtz % 64][SDSC.txtx % 64];
		if (SDSC.pel != 0)
			((int*)FAKE->pixels)[y * W2 + SDSC.xrw] = SDSC.pel;
	}
}
