/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <osak@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 03:08:27 by osak              #+#    #+#             */
/*   Updated: 2019/07/01 03:08:33 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void			perspective_transformation(t_system *sys)
{
	SDSC.scale1.x = HFOV / SDSC.tz1;
	SDSC.scale1.y = VFOV / SDSC.tz1;
	SDSC.x1 = W / 2 - (int)(SDSC.tx1 * SDSC.scale1.x);
	SDSC.scale2.x = HFOV / SDSC.tz2;
	SDSC.scale2.y = VFOV / SDSC.tz2;
	SDSC.x2 = W / 2 - (int)(SDSC.tx2 * SDSC.scale2.x);
}

void			transformation_formulas(t_system *sys)
{
	SDSC.pcos = SP->anglecos;
	SDSC.psin = SP->anglesin;
	SDSC.tx1 = SDSC.v1.x * SDSC.psin - SDSC.v1.y * SDSC.pcos;
	SDSC.tz1 = SDSC.v1.x * SDSC.pcos + SDSC.v1.y * SDSC.psin;
	SDSC.tx2 = SDSC.v2.x * SDSC.psin - SDSC.v2.y * SDSC.pcos;
	SDSC.tz2 = SDSC.v2.x * SDSC.pcos + SDSC.v2.y * SDSC.psin;
}

void			find_sprite_end(t_system *sys, float dist)
{
	float v1_x;
	float v1_y;
	float v2_x;
	float v2_y;

	v1_x = (SDSC.sect->item[SDSCS.item_num].position.x - SP->where.x) / dist;
	v1_y = (SDSC.sect->item[SDSCS.item_num].position.y - SP->where.y) / dist;
	v2_x = -v1_y;
	v2_y = v1_x;
	SDSC.v1.x = (SDSC.sect->item[SDSCS.item_num].position.x - SP->where.x);
	SDSC.v1.y = (SDSC.sect->item[SDSCS.item_num].position.y - SP->where.y);
	SDSC.v2.x = (v2_x * 1) + SDSC.sect->item[SDSCS.item_num].position.x
				- SP->where.x;
	SDSC.v2.y = (v2_y * 1) + SDSC.sect->item[SDSCS.item_num].position.y
				- SP->where.y;
}

int				calc_sprite_interactions(t_system *sys)
{
	int ret;

	if (SDSCS.dist < 2)
	{
		sys->dev.obj++;
		sys->dev.time = SDL_GetTicks();
		sys->dev.flag = 0;
		ret = SDSC.sect->item[SDSCS.item_num].item_id;
		SDSC.sect->item[SDSCS.item_num].item_id = -1;
		return (ret);
	}
	return (-1);
}

int				calc_sprite_view(t_system *sys)
{
	int		ret;
	float	abx;
	float	aby;

	abx = (SP->where.x - SDSC.sect->item[SDSCS.item_num].position.x);
	aby = (SP->where.y - SDSC.sect->item[SDSCS.item_num].position.y);
	SDSCS.dist = (float)sqrt(abx * abx + aby * aby);
	ret = calc_sprite_interactions(sys);
	if (ret != -1)
		return (ret);
	find_sprite_end(sys, SDSCS.dist);
	transformation_formulas(sys);
	if (SDSC.tz1 <= 0 && SDSC.tz2 <= 0)
		return (-1);
	perspective_transformation(sys);
	find_sprite_visual(sys, SDSCS.dist);
	return (10);
}
