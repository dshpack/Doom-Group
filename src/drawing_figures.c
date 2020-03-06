/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_figures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <dshpack@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 04:29:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/07/01 04:29:00 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void		draw_created_rect(int n, t_data *d, t_render *ren)
{
	t_sect		s_tmp;
	t_d_line	line;

	s_tmp = d->sec[n];
	line = (t_d_line){ s_tmp.figure.first, s_tmp.figure.second, ren->color };
	if (!is_portal_this_wall(n, line, d->sec))
		bolder_line(line, 't', ren->scr, &draw_rect);
	line = (t_d_line){ s_tmp.figure.first, s_tmp.figure.third, ren->color };
	if (!is_portal_this_wall(n, line, d->sec))
		bolder_line(line, 'l', ren->scr, &draw_rect);
	line = (t_d_line){ s_tmp.figure.second, s_tmp.figure.fourth, ren->color };
	if (!is_portal_this_wall(n, line, d->sec))
		bolder_line(line, 'r', ren->scr, &draw_rect);
	line = (t_d_line){ s_tmp.figure.third, s_tmp.figure.fourth, ren->color };
	if (!is_portal_this_wall(n, line, d->sec))
		bolder_line(line, 'd', ren->scr, &draw_rect);
}

void		draw_created_trngl_d_r(int n, int type, t_data *d, t_render *ren)
{
	t_sect			s_tmp;
	t_d_line		line;
	void			(*funk)();

	s_tmp = d->sec[n];
	if (type == TRIANGLE_DOWN_R)
		funk = draw_triangle_down_r;
	else if (type == TRIANGLE_DOWN_L)
		funk = draw_triangle_down_l;
	else if (type == TRIANGLE_UP_R)
		funk = draw_triangle_right;
	else if (type == TRIANGLE_UP_L)
		funk = draw_triangle_left;
	line = (t_d_line){ s_tmp.figure.first, s_tmp.figure.third, ren->color };
	if (!is_portal_this_wall(n, line, d->sec))
		bolder_line2(line, 'l', ren->scr, funk);
	line = (t_d_line){ s_tmp.figure.first, s_tmp.figure.second, ren->color };
	if (!is_portal_this_wall(n, line, d->sec))
		bolder_line2(line, 'r', ren->scr, funk);
	line = (t_d_line){ s_tmp.figure.second, s_tmp.figure.third, ren->color };
	if (!is_portal_this_wall(n, line, d->sec))
		bolder_line2(line, 'd', ren->scr, funk);
}

void		draw_created_sectors(t_env *env)
{
	size_t		i;
	Uint32		color;

	i = UINT64_MAX;
	while (++i < env->sdata.cout)
		if (env->sdata.sec[i].id > -1)
		{
			color = env->flags->sec.active ==
					env->sdata.sec[i].id ? 0xD2691E : 0x00FF7F;
			if (env->sdata.sec[i].type == RECTANGLE)
				draw_created_rect(i, &env->sdata,
							&((t_render){ env->graph->screen_srf, color }));
			else if (env->sdata.sec[i].type > RECTANGLE)
				draw_created_trngl_d_r(i, env->sdata.sec[i].type, &env->sdata,
							&((t_render){ env->graph->screen_srf, color }));
			if (env->sdata.sec[i].id > -1 && env->sdata.sec[i].obj.is_live > -1)
				surf_to_scr((t_xy){env->sdata.sec[i].obj.coord.x,
							env->sdata.sec[i].obj.coord.y}, env->graph,
							&env->graph->obj[env->sdata.sec[i].obj.type - 30],
							env->graph->menu_cont);
		}
}
