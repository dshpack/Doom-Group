/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 18:06:56 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/28 18:08:18 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void		mvs1(int s, t_sector *sector, float const *eyeh, t_system *sys)
{
	float		hl;
	float		hh;
	t_xy		d;
	t_player	*player;

	player = SP;
	hl = 9e9;
	hh = -9e9;
	if (sector->neighbours[s] >= 0)
	{
		hl = MAX(sector->floor, SS[sector->neighbours[s]].floor);
		hh = MIN(sector->ceil, SS[sector->neighbours[s]].ceil);
	}
	if (hh < PW.z + HEADMARGIN || hl > PW.z - *eyeh + KNEEHEIGHT)
	{
		d.x = SEV[s + 1].x - SEV[s + 0].x;
		d.y = SEV[s + 1].y - SEV[s + 0].y;
		PV.x = d.x * (PV.x * d.x + PV.y * d.y) / (SQ(d.x) + SQ(d.y));
		PV.y = d.y * (PV.x * d.x + PV.y * d.y) / (SQ(d.x) + SQ(d.y));
		PP.moving = 0;
	}
}

void		mvs(t_player *player, t_system *sys, float const *eyeh, int s)
{
	t_sector	*sector;
	size_t		i;

	i = (size_t)s;
	sector = &SS[player->num_sect];
	while (++i < sector->npoints)
	{
		if (intersect_box((t_xy) {PW.x, PW.y},
			(t_xy) {PW.x + PV.x, PW.y + PV.y},
			(t_xy) {SEV[s + 0].x, SEV[s + 0].y},
			(t_xy) {SEV[s + 1].x, SEV[s + 1].y})
			&& point_side((t_xy) {PW.x + PV.x, PW.y + PV.y},
			(t_xy) {SEV[s + 0].x, SEV[s + 0].y},
			(t_xy) {SEV[s + 1].x, SEV[s + 1].y}) < 0)
		{
			SP = player;
			s = (int)i;
			mvs1(s, sector, eyeh, sys);
			player = SP;
		}
	}
	move_player(player, SS, (t_xy){PV.x, PV.y});
	PP.falling = 1;
}

void		falling(t_player *player, t_system *sys, float const eyeheight)
{
	float		nextz;

	PV.z -= 0.05f;
	nextz = PW.z + PV.z;
	if (PV.z < 0 && nextz <
		SS[player->num_sect].floor + eyeheight)
	{
		PW.z = SS[player->num_sect].floor + eyeheight;
		PV.z = 0;
		PP.falling = 0;
		PP.ground = 1;
	}
	else if (PV.z > 0 && nextz > SS[player->num_sect].ceil)
	{
		PV.z = 0;
		PP.falling = 1;
	}
	if (PP.falling)
	{
		PW.z += PV.z;
		PP.moving = 1;
	}
}
