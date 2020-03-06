/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 17:42:41 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/28 17:42:43 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void		view_frustrum_help(t_system *sys)
{
	if (SDSC.tz1 < SDSC.nearz)
	{
		if (SDSC.i1.y > 0)
		{
			SDSC.tx1 = SDSC.i1.x;
			SDSC.tz1 = SDSC.i1.y;
		}
		else
		{
			SDSC.tx1 = SDSC.i2.x;
			SDSC.tz1 = SDSC.i2.y;
		}
	}
}

void		view_frustrum_next(t_system *sys)
{
	view_frustrum_help(sys);
	if (SDSC.tz2 < SDSC.nearz)
	{
		if (SDSC.i1.y > 0)
		{
			SDSC.tx2 = SDSC.i1.x;
			SDSC.tz2 = SDSC.i1.y;
		}
		else
		{
			SDSC.tx2 = SDSC.i2.x;
			SDSC.tz2 = SDSC.i2.y;
		}
	}
}

void		draw_screen_init(t_system *sys, int *renderedsectors)
{
	SDSC.tail = SDSC.queue;
	SDSC.head = SDSC.queue;
	SDSC.x = 0;
	while (++SDSC.x < W)
		SDSC.ytop[SDSC.x] = 0;
	SDSC.x = 0;
	while (++SDSC.x < W)
		SDSC.ybottom[SDSC.x] = H - 1;
	SDSC.n = -1;
	while (++SDSC.n < sys->num_sectors)
		renderedsectors[SDSC.n] = 0;
	*SDSC.head = (t_item) {sys->player->num_sect, 0, W - 1 };
	if (++SDSC.head == SDSC.queue + MAX_QUEUE)
		SDSC.head = SDSC.queue;
}

void		before_view_frustrum(t_system *sys)
{
	SDSC.nearz = 1e-4f;
	SDSC.farz = 5;
	SDSC.nearside = 1e-5f;
	SDSC.farside = 20.f;
	SDSC.i1 = intersect_def((t_xy) {SDSC.tx1, SDSC.tz1},
			(t_xy) {SDSC.tx2, SDSC.tz2}, (t_xy) {-SDSC.nearside,
			SDSC.nearz}, (t_xy) {-SDSC.farside, SDSC.farz});
	SDSC.i2 = intersect_def((t_xy) {SDSC.tx1, SDSC.tz1},
			(t_xy) {SDSC.tx2, SDSC.tz2}, (t_xy) {SDSC.nearside,
			SDSC.nearz}, (t_xy) {SDSC.farside, SDSC.farz});
	SDSC.org1.x = SDSC.tx1;
	SDSC.org1.y = SDSC.tz1;
	SDSC.org2.x = SDSC.tx2;
	SDSC.org2.y = SDSC.tz2;
}

void		after_view_frustrum(t_system *sys)
{
	if (ABS(SDSC.tx2 - SDSC.tx1) > ABS(SDSC.tz2 - SDSC.tz1))
	{
		SDSC.u0 = (int)((SDSC.tx1 - SDSC.org1.x) * 127 /
			(SDSC.org2.x - SDSC.org1.x));
		SDSC.u1 = (int)((SDSC.tx2 - SDSC.org1.x) * 127 /
			(SDSC.org2.x - SDSC.org1.x));
	}
	else
	{
		SDSC.u0 = (int)((SDSC.tz1 - SDSC.org1.y) * 127 /
			(SDSC.org2.y - SDSC.org1.y));
		SDSC.u1 = (int)((SDSC.tz2 - SDSC.org1.y) * 127 /
			(SDSC.org2.y - SDSC.org1.y));
	}
}
