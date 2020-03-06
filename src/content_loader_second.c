/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_loader_second.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <dshpack@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 01:06:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/07/01 01:06:00 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl_editor.h"

void		initer_first(t_graph *g)
{
	g->menu[21].x = 560;
	g->menu[21].y = 0;
	g->menu[21].w = 70;
	g->menu[21].h = 70;
	g->menu[34].x = 560;
	g->menu[34].y = 70;
	g->menu[34].w = 70;
	g->menu[34].h = 70;
	g->menu[22].x = 630;
	g->menu[22].y = 0;
	g->menu[22].w = 70;
	g->menu[22].h = 70;
	g->menu[35].x = 630;
	g->menu[35].y = 70;
	g->menu[35].w = 70;
	g->menu[35].h = 70;
	g->menu[23].x = 700;
	g->menu[23].y = 0;
	g->menu[23].w = 70;
	g->menu[23].h = 70;
	g->menu[36].x = 700;
	g->menu[36].y = 70;
	g->menu[36].w = 70;
	g->menu[36].h = 70;
}

void		initer_second(t_graph *g)
{
	g->menu[21].x = 560;
	g->menu[21].y = 0;
	g->menu[21].w = 70;
	g->menu[21].h = 70;
	g->menu[34].x = 560;
	g->menu[34].y = 70;
	g->menu[34].w = 70;
	g->menu[34].h = 70;
	g->menu[22].x = 630;
	g->menu[22].y = 0;
	g->menu[22].w = 70;
	g->menu[22].h = 70;
	g->menu[35].x = 630;
	g->menu[35].y = 70;
	g->menu[35].w = 70;
	g->menu[35].h = 70;
	g->menu[23].x = 700;
	g->menu[23].y = 0;
	g->menu[23].w = 70;
	g->menu[23].h = 70;
	g->menu[36].x = 700;
	g->menu[36].y = 70;
	g->menu[36].w = 70;
	g->menu[36].h = 70;
}

void		mim1(t_graph *g)
{
	g->menu[24].x = 770;
	g->menu[24].y = 0;
	g->menu[24].w = 70;
	g->menu[24].h = 70;
	g->menu[37].x = 770;
	g->menu[37].y = 70;
	g->menu[37].w = 70;
	g->menu[37].h = 70;
	g->menu[25].x = 840;
	g->menu[25].y = 0;
	g->menu[25].w = 70;
	g->menu[25].h = 70;
	g->menu[38].x = 840;
	g->menu[38].y = 70;
	g->menu[38].w = 70;
	g->menu[38].h = 70;
	g->menu[26].x = 910;
	g->menu[26].y = 0;
	g->menu[26].w = 70;
	g->menu[26].h = 70;
	g->menu[39].x = 910;
	g->menu[39].y = 70;
	g->menu[39].w = 70;
	g->menu[39].h = 70;
}

void		mim2(t_graph *g)
{
	g->menu[27].x = 980;
	g->menu[27].y = 0;
	g->menu[27].w = 70;
	g->menu[27].h = 70;
	g->menu[40].x = 980;
	g->menu[40].y = 70;
	g->menu[40].w = 70;
	g->menu[40].h = 70;
	g->menu[28].x = 1050;
	g->menu[28].y = 0;
	g->menu[28].w = 70;
	g->menu[28].h = 70;
	g->menu[41].x = 1050;
	g->menu[41].y = 70;
	g->menu[41].w = 70;
	g->menu[41].h = 70;
	g->menu[29].x = 1120;
	g->menu[29].y = 0;
	g->menu[29].w = 70;
	g->menu[29].h = 70;
	g->menu[42].x = 1120;
	g->menu[42].y = 70;
	g->menu[42].w = 70;
	g->menu[42].h = 70;
}

void		menu_initer_main(t_graph *g)
{
	initer_first(g);
	mim1(g);
	mim2(g);
	g->menu[30].x = 1190;
	g->menu[30].y = 0;
	g->menu[30].w = 70;
	g->menu[30].h = 70;
	g->menu[43].x = 1190;
	g->menu[43].y = 70;
	g->menu[43].w = 70;
	g->menu[43].h = 70;
}
