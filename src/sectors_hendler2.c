/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sectors_hendler2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <osak@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 04:30:12 by osak              #+#    #+#             */
/*   Updated: 2019/07/01 04:30:14 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl_editor.h"

void		init_sector(t_pnt mouse, t_sect *s, t_env *env)
{
	if (env->sdata.tmp_type == RECTANGLE)
	{
		s->figure = (t_sec_rect){ (t_pnt){ mouse.x, mouse.y },
		(t_pnt){ mouse.x + ZOOM * env->sdata.tmp_w, mouse.y },
		(t_pnt){ mouse.x, mouse.y + ZOOM * env->sdata.tmp_h },
		(t_pnt){ mouse.x + ZOOM * env->sdata.tmp_w,
		mouse.y + ZOOM * env->sdata.tmp_h } };
	}
	else
		init_triangle_dots(mouse, s, env);
	s->type = env->sdata.tmp_type;
	s->id = env->sdata.cout;
	s->obj_cout = 0;
	s->obj.is_live = -1;
	s->ceiling = 20;
	s->floor = 0;
}

void		init_obj(t_pnt mouse, t_inner *obj, int object_btn)
{
	obj->coord.x = mouse.x;
	obj->coord.y = mouse.y;
	obj->type = object_btn;
}

void		searching_nearest_point(t_eflags *flags, t_env *env, int is_sec)
{
	int		first_pnt;
	int		second_pnt;
	int		pos_x;
	int		pos_y;

	first_pnt = ((flags->curr_pos.x - OFFSET_X) / ZOOM) * ZOOM + OFFSET_X;
	second_pnt = first_pnt + ZOOM;
	pos_x = (flags->curr_pos.x > (first_pnt + 24) / 2) ? first_pnt : second_pnt;
	first_pnt = ((flags->curr_pos.y - OFFSET_Y) / ZOOM) * ZOOM + OFFSET_Y;
	second_pnt = first_pnt + ZOOM;
	pos_y = (flags->curr_pos.y > (first_pnt + 24) / 2) ? first_pnt : second_pnt;
	if (is_sec)
		init_sector((t_pnt){ pos_x, pos_y }, env->sdata.tmp_sec, env);
	else
		init_obj((t_pnt){ pos_x, pos_y }, env->sdata.tmp_obj,
		env->flags->sec.object_btn);
}
