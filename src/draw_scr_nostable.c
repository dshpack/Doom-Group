/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scr_nostable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:57:03 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/29 20:57:04 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#define CONT (SDSC.x2 < SDSC.now.sx1 || SDSC.x1 > SDSC.now.sx2)

void	for_neighbour(t_system *sys)
{
	SDSC.ny.a = scaler_next(&SDSC.nya_int);
	SDSC.ny.b = scaler_next(&SDSC.nyb_int);
	SDSC.cny.a = CLAMP(SDSC.ny.a, SDSC.ytop[SDSC.xrw], SDSC.ybottom[SDSC.xrw]);
	SDSC.cny.b = CLAMP(SDSC.ny.b, SDSC.ytop[SDSC.xrw], SDSC.ybottom[SDSC.xrw]);
	vline2((t_int_xyz) {SDSC.xrw, SDSC.cy.a, SDSC.cny.a - 1},
		scaler_init((t_int_xyz) {SDSC.y.a, SDSC.cy.a, SDSC.y.b}, 0, 63),
		&SDSC.sect->uppertextures[SDSC.s], sys);
	vline2((t_int_xyz) {SDSC.xrw, SDSC.cy.a, SDSC.cny.a - 1},
		scaler_init((t_int_xyz) {SDSC.y.a, SDSC.cy.a, SDSC.y.b}, 0, 63),
		&SDSC.sect->uppertextures[SDSC.s], sys);
	SDSC.ytop[SDSC.xrw] = CLAMP(MAX(SDSC.cy.a, SDSC.cny.a),
								SDSC.ytop[SDSC.xrw], H - 1);
	vline2((t_int_xyz) {SDSC.xrw, SDSC.cny.b + 1, SDSC.cy.b},
		scaler_init((t_int_xyz) {SDSC.y.a, SDSC.cny.b + 1, SDSC.y.b}, 0, 63),
		&SDSC.sect->lowertextures[SDSC.s], sys);
	SDSC.ybottom[SDSC.xrw] = CLAMP(MIN(SDSC.cy.b, SDSC.cny.b),
				0, SDSC.ybottom[SDSC.xrw]);
}

void	cycle_xrw_endx(t_system *sys)
{
	while (++SDSC.xrw <= SDSC.endx)
	{
		acquire_coords(sys);
		for_cycle(sys);
		if (SDSC.neighbour >= 0)
			for_neighbour(sys);
		else
		{
			vline2((t_int_xyz) {SDSC.xrw, SDSC.cy.a, SDSC.cy.b},
				scaler_init((t_int_xyz)
					{SDSC.y.a, SDSC.cy.a, SDSC.y.b}, 0, 127),
				&SDSC.sect->uppertextures[SDSC.s], sys);
		}
	}
	if (SDSC.neighbour >= 0 &&
		SDSC.endx >= SDSC.beginx &&
		(SDSC.head + MAX_QUEUE +
		1 - SDSC.tail) % MAX_QUEUE)
	{
		*SDSC.head = (t_item) {SDSC.neighbour,
			SDSC.beginx, SDSC.endx};
		if (++SDSC.head == SDSC.queue + MAX_QUEUE)
			SDSC.head = SDSC.queue;
	}
}

void	include_in_drawscreen(t_system *sys)
{
	if (SDSC.now.sectorno <= (int)(sys->num_sectors - 1))
		SDSC.sect = &SS[SDSC.now.sectorno];
	SDSC.s = -1;
	while (++(sys->dscreen.s) < sys->dscreen.sect->npoints)
	{
		transform_vertices(sys);
		if (SDSC.tz1 <= 0 && SDSC.tz2 <= 0)
			continue;
		if (SDSC.tz1 <= 0 || SDSC.tz2 <= 0)
		{
			before_view_frustrum(sys);
			view_frustrum_next(sys);
			after_view_frustrum(sys);
		}
		scales(sys);
		if (SDSC.x1 >= SDSC.x2 || CONT)
			continue;
		transform_floor_ceiling(sys);
		check_the_edge_type(sys);
		before_cycle_helper(sys);
		cycle_xrw_endx(sys);
	}
}
