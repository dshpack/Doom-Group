/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 02:30:02 by osak              #+#    #+#             */
/*   Updated: 2019/07/01 02:30:02 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"
#include "defines.h"

void			set_color(t_system *sys, int x, int y, int tex_num)
{
	int color;

	if (SDSC.u < SPR_H && SDSC.v < SPR_W)
	{
		color = SDSC.card[tex_num][SDSC.u][SDSC.v];
		if (color != 0x000000)
		{
			((int*)sys->fake_surface->pixels)[y * W2 + x] = color;
		}
	}
}

void			draw_sprites_in_sector(t_system *sys)
{
	int res;

	SDSCS.item_num = 0;
	while (SDSCS.item_num < 2)
	{
		if (SDSC.sect->item[SDSCS.item_num].item_id >= 0)
		{
			res = calc_sprite_view(sys);
			if (res == 10)
			{
				if (SDSC.sect->item[SDSCS.item_num].item_id == YELLOW_KEY)
					draw_key_sprite(sys, YELLOW_KEY);
				if (SDSC.sect->item[SDSCS.item_num].item_id == RED_KEY)
					draw_key_sprite(sys, RED_KEY);
			}
			else if (res >= 0)
			{
				if (res == YELLOW_KEY)
					SP->inv.yellow_key = 1;
				else if (res == RED_KEY)
					SP->inv.red_key = 1;
			}
		}
		SDSCS.item_num++;
	}
}

void			casting(t_system *sys)
{
	int renderedsectors[sys->num_sectors];

	draw_screen_init(sys, renderedsectors);
	sys->dscreen.sect = &sys->sectors[SDSC.now.sectorno];
	while (SDSC.head != SDSC.tail)
	{
		SDSC.now = *SDSC.tail;
		if (++SDSC.tail == SDSC.queue + MAX_QUEUE)
			SDSC.tail = SDSC.queue;
		if (renderedsectors[SDSC.now.sectorno] & 0x21)
			continue;
		++renderedsectors[SDSC.now.sectorno];
		draw_sprites_in_sector(sys);
		++renderedsectors[SDSC.now.sectorno];
	}
}

void			stand_sprite(t_system *sys)
{
	if (SDSC.now.sectorno == 0)
	{
		sys->sectors[SDSC.now.sectorno].item[0].item_id = YELLOW_KEY;
		sys->sectors[SDSC.now.sectorno].item[0].position.x = 8;
		sys->sectors[SDSC.now.sectorno].item[0].position.y = 14;
	}
	sys->dev = *(t_dev*)malloc(sizeof(t_dev));
}

void			sprite_casting(t_system *sys)
{
	if (sys->map_i == 2 && (sys->player->inv.yellow_key != 1))
	{
		stand_sprite(sys);
		casting(sys);
	}
}
