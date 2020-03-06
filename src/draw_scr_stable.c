/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scr_stable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 17:46:22 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/28 17:46:24 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void		check_the_edge_type(t_system *sys)
{
	SDSC.neighbour = SDSC.sect->neighbours[SDSC.s];
	SDSC.nyceil = 0;
	SDSC.nyfloor = 0;
	if (SDSC.neighbour >= 0)
	{
		SDSC.nyceil = sys->sectors[SDSC.neighbour].ceil
				- sys->player->where.z;
		SDSC.nyfloor = sys->sectors[SDSC.neighbour].floor
				- sys->player->where.z;
	}
	SDSC.ny1.a = H / 2 + (int)(-YAW(SDSC.nyceil,
			SDSC.tz1) * SDSC.scale1.y);
	SDSC.ny1.b = H / 2 + (int)(-YAW(SDSC.nyfloor,
			SDSC.tz1) * SDSC.scale1.y);
	SDSC.ny2.a = H / 2 + (int)(-YAW(SDSC.nyceil,
			SDSC.tz2) * SDSC.scale2.y);
	SDSC.ny2.b = H / 2 + (int)(-YAW(SDSC.nyfloor,
			SDSC.tz2) * SDSC.scale2.y);
	SDSC.beginx = MAX(SDSC.x1, SDSC.now.sx1);
	SDSC.endx = MIN(SDSC.x2, SDSC.now.sx2);
}

void		acquire_coords(t_system *sys)
{
	sys->tex_tx = (int)((SDSC.u0 * ((SDSC.x2 - SDSC.xrw) * SDSC.tz2)
							+ SDSC.u1 * ((SDSC.xrw - SDSC.x1) * SDSC.tz1))
							/ ((SDSC.x2 - SDSC.xrw) * SDSC.tz2
							+ (SDSC.xrw - SDSC.x1) * SDSC.tz1));
	SDSC.z = (int)((SDSC.xrw - SDSC.x1)
			* (SDSC.tz2 - SDSC.tz1) /
			(SDSC.x2 - SDSC.x1) + SDSC.tz1) * 8;
	SDSC.y.a = (SDSC.xrw - SDSC.x1) *
			(SDSC.y2.a - SDSC.y1.a) /
			(SDSC.x2 - SDSC.x1) + SDSC.y1.a;
	SDSC.y.b = (SDSC.xrw - SDSC.x1) *
			(SDSC.y2.b - SDSC.y1.b) /
			(SDSC.x2 - SDSC.x1) + SDSC.y1.b;
	SDSC.cy.a = CLAMP(SDSC.y.a,
					SDSC.ytop[SDSC.xrw],
					SDSC.ybottom[SDSC.xrw]);
	SDSC.cy.b = CLAMP(SDSC.y.b,
					SDSC.ytop[SDSC.xrw],
					SDSC.ybottom[SDSC.xrw]);
}

void		vline2(t_int_xyz xyz, t_scaler ty, const t_textureset *t,
	t_system *sys)
{
	int			*pix;
	int			y;
	unsigned	txty;

	pix = (int*)sys->fake_surface->pixels;
	xyz.y = CLAMP(xyz.y, 0, H - 1);
	xyz.z = CLAMP(xyz.z, 0, H - 1);
	pix += xyz.y * W2 + xyz.x;
	y = xyz.y;
	while (y <= xyz.z)
	{
		txty = scaler_next(&ty);
		if (t->texture[sys->tex_tx % 64][txty % 64] == 0)
			*pix = ((int *)sys->fake_surface->pixels)[y * W2 + SDSC.xrw];
		else
			*pix = t->texture[sys->tex_tx % 64][txty % 64];
		pix += W2;
		y++;
	}
}
