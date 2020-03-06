/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sectors_hendler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <dshpack@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:30:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/06/13 19:30:00 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl_editor.h"

t_sec_rect	init_triangle_dots(t_pnt mouse, t_sect *s, t_env *env)
{
	t_sec_rect		rect;

	RF = (t_pnt){ mouse.x, mouse.y };
	RS = (t_pnt){ mouse.x, mouse.y + ZOOM * ENVS.tmp_h };
	RT = (t_pnt){ mouse.x - ZOOM * ENVS.tmp_w, mouse.y + ZOOM * ENVS.tmp_h };
	rect.fourth = (t_pnt){ 0, 0 };
	if (ENVS.tmp_type == TRIANGLE_DOWN_R)
		return (s->figure = rect);
	RF = (t_pnt){ mouse.x, mouse.y };
	RS = (t_pnt){ mouse.x, mouse.y + ZOOM * ENVS.tmp_h };
	RT = (t_pnt){ mouse.x + ZOOM * ENVS.tmp_w, mouse.y + ZOOM * ENVS.tmp_h };
	if (ENVS.tmp_type == TRIANGLE_DOWN_L)
		return (s->figure = rect);
	RF = (t_pnt){ mouse.x, mouse.y };
	RS = (t_pnt){ mouse.x + ZOOM * ENVS.tmp_w, mouse.y };
	RT = (t_pnt){ mouse.x + ZOOM * ENVS.tmp_w, mouse.y + ZOOM * ENVS.tmp_h };
	if (ENVS.tmp_type == TRIANGLE_UP_R)
		return (s->figure = rect);
	RF = (t_pnt){ mouse.x, mouse.y };
	RS = (t_pnt){ mouse.x + ZOOM * ENVS.tmp_w, mouse.y };
	RT = (t_pnt){ mouse.x, mouse.y + ZOOM * ENVS.tmp_h };
	if (ENVS.tmp_type == TRIANGLE_UP_L)
		return (s->figure = rect);
	return (rect);
}

void		cre_ob(t_map *map, t_env *env, t_eflags *f, t_sect *s)
{
	t_inner		*tmp;

	tmp = ENVS.tmp_obj;
	if (s->obj.type == 0
		&& map->dot[CALC_Y(tmp->coord.y)][CALC_X(tmp->coord.x)].status == 1
		&& map->dot[CALC_Y(tmp->coord.y)][CALC_X(tmp->coord.x)].sect_num ==
		f->sec.active)
	{
		s->obj.coord.x = tmp->coord.x - 10;
		s->obj.coord.y = tmp->coord.y - 10;
		s->obj.type = tmp->type;
		s->obj.is_live = TRUE;
		free(ENVS.tmp_obj);
		ENVS.tmp_obj = NULL;
		s->obj_cout++;
	}
}

void		creating_objects(t_env *env, t_map *map, t_sect *s, t_eflags *f)
{
	if (s->obj_cout == 4)
		return ;
	if (!f->sec.create_obj)
		searching_nearest_point(f, env, FALSE);
	else if (ENVS.tmp_obj->type == TRUE_PL)
	{
		if (ENVS.tmp_obj->type == TRUE_PL && !f->player.status)
		{
			f->player.coords.x = ENVS.tmp_obj->coord.x;
			f->player.coords.y = ENVS.tmp_obj->coord.y;
			f->player.status = TRUE;
		}
		else
			f->player.err_msg = TRUE;
		cre_ob(map, env, f, s);
		f->sec.create_obj = FALSE;
	}
	else
		f->sec.create_obj = FALSE;
}

void		sect_w(t_env *env, t_sect **tmp)
{
	if (ENVS.cout >= (unsigned int)ENVS.store_size)
	{
		ENVS.store_size *= 2;
		ENVS.sec = recreate_sector_storage(ENVS.store_size,
	ENVS.cout, ENVS.sec);
	}
	copy_sectors(*tmp, ENVS.sec + ENVS.cout, 1);
	fill_up_map_cells(&env->map, *tmp);
	ENVS.cout++;
	free(*tmp);
	*tmp = NULL;
}

void		sectors_worker(t_eflags *flags, t_elem *sec,
										t_env *env, t_sect **tmp)
{
	t_sec_rect		*figure;

	if (!(*tmp) && !(*tmp = (t_sect *)malloc(sizeof(t_sect))))
		ft_putstr("LOW MEMORY and EXIT");
	figure = &(ENVS.tmp_sec->figure);
	if (!ENVS.tmp_obj)
		if (!(ENVS.tmp_obj = (t_inner *)malloc(sizeof(t_inner))))
			ft_putstr("LOW MEMORY and EXIT");
	if (sec->type_btn > NONE && !sec->create_sec && (ENVS.tmp_type =
			flags->sec.type_btn))
		searching_nearest_point(flags, env, TRUE);
	else if (((FS.x <= WIREFRAME_W && FS.y <= WIREFRAME_H && FS.x >= OFFSET_X
		&& FS.y >= OFFSET_Y && FF.x <= WIREFRAME_W && FF.y <= WIREFRAME_H
		&& FF.x >= OFFSET_X && FF.y >= OFFSET_Y && FT.x <= WIREFRAME_W
		&& FT.y <= WIREFRAME_H && FT.x >= OFFSET_X && FT.y >= OFFSET_Y)
		|| ((*tmp)->type == RECTANGLE && (FFO.x <= WIREFRAME_W
		&& FFO.y <= WIREFRAME_H && FFO.x >= OFFSET_X && FFO.y >= OFFSET_Y)))
		&& !is_place_occupied(*tmp, env->map) && sec->create_sec)
		sect_w(env, tmp);
	else if (sec->type_btn == NONE && !sec->create_sec && flags->sec.active > -1
		&& flags->sec.object_btn > -1)
		creating_objects(env, &env->map, &ENVS.sec[flags->sec.active],
			flags);
	sec->create_sec = FALSE;
}
