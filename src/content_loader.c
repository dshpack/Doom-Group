/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <dshpack@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:49:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/04/11 20:49:00 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl_editor.h"

void		init_menu_rect(t_graph *g)
{
	g->menu[0].x = 140;
	g->menu[0].y = 160;
	g->menu[0].w = 32;
	g->menu[0].h = 32;
	g->menu[1].x = 172;
	g->menu[1].y = 160;
	g->menu[1].w = 32;
	g->menu[1].h = 32;
	g->menu[2].x = 204;
	g->menu[2].y = 160;
	g->menu[2].w = 32;
	g->menu[2].h = 32;
	g->menu[3].x = 236;
	g->menu[3].y = 160;
	g->menu[3].w = 32;
	g->menu[3].h = 32;
	g->menu[4].x = 380;
	g->menu[4].y = 140;
	g->menu[4].w = 32;
	g->menu[4].h = 32;
	g->menu[5].x = 0;
	g->menu[5].y = 160;
	g->menu[5].w = 140;
	g->menu[5].h = 32;
}

void		init_menu_rect_second(t_graph *g)
{
	g->menu[6].x = 240;
	g->menu[6].y = 140;
	g->menu[6].w = 140;
	g->menu[6].h = 32;
	g->menu[7].x = 0;
	g->menu[7].y = 0;
	g->menu[7].w = 0;
	g->menu[7].h = 0;
	g->menu[8].x = 0;
	g->menu[8].y = 0;
	g->menu[8].w = 70;
	g->menu[8].h = 70;
	g->menu[9].x = 0;
	g->menu[9].y = 70;
	g->menu[9].w = 70;
	g->menu[9].h = 70;
	g->menu[10].x = 70;
	g->menu[10].y = 0;
	g->menu[10].w = 70;
	g->menu[10].h = 70;
	g->menu[11].x = 70;
	g->menu[11].y = 70;
	g->menu[11].w = 70;
	g->menu[11].h = 70;
}

void		init_menu_rect_third(t_graph *g)
{
	g->menu[12].x = 140;
	g->menu[12].y = 0;
	g->menu[12].w = 70;
	g->menu[12].h = 70;
	g->menu[13].x = 140;
	g->menu[13].y = 70;
	g->menu[13].w = 70;
	g->menu[13].h = 70;
	g->menu[14].x = 210;
	g->menu[14].y = 0;
	g->menu[14].w = 70;
	g->menu[14].h = 70;
	g->menu[15].x = 210;
	g->menu[15].y = 70;
	g->menu[15].w = 70;
	g->menu[15].h = 70;
	g->menu[16].x = 280;
	g->menu[16].y = 0;
	g->menu[16].w = 70;
	g->menu[16].h = 70;
	g->menu[17].x = 280;
	g->menu[17].y = 70;
	g->menu[17].w = 70;
	g->menu[17].h = 70;
}

void		init_menu_rect_fourth(t_graph *g)
{
	g->menu[18].x = 350;
	g->menu[18].y = 0;
	g->menu[18].w = 70;
	g->menu[18].h = 70;
	g->menu[31].x = 350;
	g->menu[31].y = 70;
	g->menu[31].w = 70;
	g->menu[31].h = 70;
	g->menu[19].x = 420;
	g->menu[19].y = 0;
	g->menu[19].w = 70;
	g->menu[19].h = 70;
	g->menu[32].x = 420;
	g->menu[32].y = 70;
	g->menu[32].w = 70;
	g->menu[32].h = 70;
	g->menu[20].x = 490;
	g->menu[20].y = 0;
	g->menu[20].w = 70;
	g->menu[20].h = 70;
	g->menu[33].x = 490;
	g->menu[33].y = 70;
	g->menu[33].w = 70;
	g->menu[33].h = 70;
}
