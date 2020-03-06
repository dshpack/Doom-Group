/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <dshpack@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:49:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/04/11 20:49:00 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl_editor.h"

void		pmc1(t_graph *g)
{
	g->textures[0].x = 330;
	g->textures[0].y = 140;
	g->textures[0].w = 70;
	g->textures[0].h = 70;
	g->textures[1].x = 400;
	g->textures[1].y = 140;
	g->textures[1].w = 70;
	g->textures[1].h = 70;
	g->textures[2].x = 470;
	g->textures[2].y = 140;
	g->textures[2].w = 70;
	g->textures[2].h = 70;
	g->textures[10].x = 400;
	g->textures[10].y = 140;
	g->textures[10].w = 70;
	g->textures[10].h = 70;
	g->textures[11].x = 470;
	g->textures[11].y = 140;
	g->textures[11].w = 70;
	g->textures[11].h = 70;
	g->textures[12].x = 540;
	g->textures[12].y = 140;
	g->textures[12].w = 70;
	g->textures[12].h = 70;
}

void		pmc2(t_graph *g)
{
	g->textures[20].x = 890;
	g->textures[20].y = 140;
	g->textures[20].w = 70;
	g->textures[20].h = 70;
	g->textures[21].x = 960;
	g->textures[21].y = 140;
	g->textures[21].w = 70;
	g->textures[21].h = 70;
	g->textures[22].x = 1030;
	g->textures[22].y = 140;
	g->textures[22].w = 70;
	g->textures[22].h = 70;
	g->obj[0].x = 255;
	g->obj[0].y = 140;
	g->obj[0].w = 20;
	g->obj[0].h = 20;
	g->obj[1].x = 0;
	g->obj[1].y = 140;
	g->obj[1].w = 20;
	g->obj[1].h = 20;
	g->obj[2].x = 20;
	g->obj[2].y = 140;
	g->obj[2].w = 20;
	g->obj[2].h = 20;
}

void		pmc3(t_graph *g)
{
	g->obj[3].x = 40;
	g->obj[3].y = 140;
	g->obj[3].w = 20;
	g->obj[3].h = 20;
	g->obj[4].x = 60;
	g->obj[4].y = 140;
	g->obj[4].w = 20;
	g->obj[4].h = 20;
	g->obj[5].x = 80;
	g->obj[5].y = 140;
	g->obj[5].w = 20;
	g->obj[5].h = 20;
	g->obj[6].x = 100;
	g->obj[6].y = 140;
	g->obj[6].w = 20;
	g->obj[6].h = 20;
	g->obj[7].x = 120;
	g->obj[7].y = 140;
	g->obj[7].w = 20;
	g->obj[7].h = 20;
	g->obj[8].x = 140;
	g->obj[8].y = 140;
	g->obj[8].w = 20;
	g->obj[8].h = 20;
}

void		pmc4(t_graph *g)
{
	g->obj[9].x = 160;
	g->obj[9].y = 140;
	g->obj[9].w = 20;
	g->obj[9].h = 20;
	g->obj[10].x = 180;
	g->obj[10].y = 140;
	g->obj[10].w = 20;
	g->obj[10].h = 20;
	g->obj[11].x = 200;
	g->obj[11].y = 140;
	g->obj[11].w = 20;
	g->obj[11].h = 20;
	g->obj[12].x = 220;
	g->obj[12].y = 140;
	g->obj[12].w = 20;
	g->obj[12].h = 20;
	g->obj[13].x = 240;
	g->obj[13].y = 140;
	g->obj[13].w = 20;
	g->obj[13].h = 20;
	g->btn_start[0].x = 1030;
	g->btn_start[0].y = 140;
	g->btn_start[0].w = 143;
	g->btn_start[0].h = 53;
}

void		prepare_menu_cont(t_graph *g)
{
	init_menu_rect(g);
	init_menu_rect_second(g);
	init_menu_rect_third(g);
	init_menu_rect_fourth(g);
	menu_initer_main(g);
	pmc1(g);
	pmc2(g);
	pmc3(g);
	pmc4(g);
	g->btn_start[1].x = 1030;
	g->btn_start[1].y = 193;
	g->btn_start[1].w = 141;
	g->btn_start[1].h = 52;
}
