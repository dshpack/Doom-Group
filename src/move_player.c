/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 18:35:51 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/28 18:35:52 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void			move_player(t_player *player, t_sector *sectors, t_xy d)
{
	t_sector	*sect;
	float		px;
	float		py;
	size_t		s;

	px = PW.x;
	py = PW.y;
	sect = &sectors[player->num_sect];
	s = -1;
	while (++s < sect->npoints)
	{
		if (sect->neighbours[s] >= 0 && intersect_box((t_xy) {px, py},
			(t_xy) {px + d.x, py + d.y}, (t_xy) {SEC_V[s + 0].x,
			SEC_V[s + 0].y}, (t_xy) {SEC_V[s + 1].x, SEC_V[s + 1].y})
			&& point_side((t_xy) {px + d.x, py + d.y}, (t_xy) {SEC_V[s + 0].x,
				SEC_V[s + 0].y}, (t_xy) {SEC_V[s + 1].x, SEC_V[s + 1].y}) < 0)
		{
			player->num_sect = sect->neighbours[s];
			break ;
		}
	}
	PW.x += d.x;
	PW.y += d.y;
	player->anglesin = sinf(player->angle);
	player->anglecos = cosf(player->angle);
}

void			pos_m(t_system *sys, t_player *player, float *eyeheight)
{
	if (PP.ducking)
		*eyeheight = DUCKHEIGHT;
	else
		*eyeheight = EYEHEIGHT;
	PP.ground = !PP.falling;
	PP.falling == 1 ? falling(player, sys, *eyeheight) : 0;
	PP.moving == 1 ? mvs(player, sys, eyeheight, -1) : 0;
}

t_xyz			define_position(char *data)
{
	t_xyz		position;
	char		**tmp;

	ft_bzero(&position, sizeof(t_xyz));
	if (data)
	{
		tmp = ft_strsplit(data, ' ');
		if (two_len(tmp) == 3 && !int_error(tmp))
		{
			position.x = ft_atoi(tmp[M1(1)]);
			position.y = ft_atoi(tmp[M1(2)]);
			position.z = ft_atoi(tmp[M1(3)]);
			position.z += EYEHEIGHT;
		}
		else
			print_error("Error, bad coords for player");
		two_del(&tmp);
	}
	return (position);
}
