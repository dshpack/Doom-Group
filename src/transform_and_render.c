/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_and_render.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 20:04:39 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/28 20:04:41 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void		transform_vertices(t_system *sys)
{
	SDSC.v1.x = SDSC.sect->vertex[SDSC.s + 0].x -
						sys->player->where.x;
	SDSC.v1.y = SDSC.sect->vertex[SDSC.s + 0].y -
			sys->player->where.y;
	SDSC.v2.x = SDSC.sect->vertex[SDSC.s + 1].x -
			sys->player->where.x;
	SDSC.v2.y = SDSC.sect->vertex[SDSC.s + 1].y -
			sys->player->where.y;
	SDSC.pcos = sys->player->anglecos;
	SDSC.psin = sys->player->anglesin;
	SDSC.tx1 = SDSC.v1.x * SDSC.psin
			- SDSC.v1.y * SDSC.pcos;
	SDSC.tz1 = SDSC.v1.x * SDSC.pcos
			+ SDSC.v1.y * SDSC.psin;
	SDSC.tx2 = SDSC.v2.x * SDSC.psin
			- SDSC.v2.y * SDSC.pcos;
	SDSC.tz2 = SDSC.v2.x * SDSC.pcos
			+ SDSC.v2.y * SDSC.psin;
	SDSC.u0 = 0;
	SDSC.u1 = 127;
}

void		yaw_calc(t_system *sys)
{
	SDSC.y1.a = H / 2 + (int)(-YAW(SDSC.yceil, SDSC.tz1) * SDSC.scale1.y);
	SDSC.y1.b = H / 2 + (int)(-YAW(SDSC.yfloor, SDSC.tz1) * SDSC.scale1.y);
	SDSC.y2.a = H / 2 + (int)(-YAW(SDSC.yceil, SDSC.tz2) * SDSC.scale2.y);
	SDSC.y2.b = H / 2 + (int)(-YAW(SDSC.yfloor, SDSC.tz2) * SDSC.scale2.y);
}

void		transform_floor_ceiling(t_system *sys)
{
	SDSC.yceil = SDSC.sect->ceil - sys->player->where.z;
	SDSC.yfloor = SDSC.sect->floor - sys->player->where.z;
	yaw_calc(sys);
}

int			scaler_next(t_scaler *i)
{
	i->cache += i->fd;
	while (i->cache >= i->ca)
	{
		i->result += i->bop;
		i->cache -= i->ca;
	}
	return (i->result);
}

void		scales(t_system *sys)
{
	SDSC.scale1.x = (W * HFOV) / (SDSC.tz1);
	SDSC.scale1.y = (H * VFOV) / (SDSC.tz1);
	SDSC.x1 = W / 2 + (int)(-SDSC.tx1
			* SDSC.scale1.x);
	SDSC.scale2.x = (W * HFOV) / (SDSC.tz2);
	SDSC.scale2.y = (H * VFOV) / (SDSC.tz2);
	SDSC.x2 = W / 2 + (int)(-SDSC.tx2
			* SDSC.scale2.x);
}
