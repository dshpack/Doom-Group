/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_visualizer2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <dshpack@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:45:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/05/22 18:45:00 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void		draw_arrows(t_graph *g, t_eflags *f)
{
	surf_to_scr((t_xy) {30, 900}, g,
		&g->menu[f->arrow.w_l], g->menu_cont);
	surf_to_scr((t_xy) {140, 900}, g,
		&g->menu[f->arrow.w_r], g->menu_cont);
	surf_to_scr((t_xy) {65, 880}, g, &g->textures[0], g->menu_cont);
	surf_to_scr((t_xy) {230, 900}, g,
		&g->menu[f->arrow.w_l], g->menu_cont);
	surf_to_scr((t_xy) {340, 900}, g,
		&g->menu[f->arrow.w_r], g->menu_cont);
	surf_to_scr((t_xy) {265, 880}, g, &g->textures[10], g->menu_cont);
	surf_to_scr((t_xy) {120, 1020}, g,
		&g->menu[f->arrow.w_l], g->menu_cont);
	surf_to_scr((t_xy) {245, 1020}, g,
		&g->menu[f->arrow.w_r], g->menu_cont);
	surf_to_scr((t_xy) {165, 1000}, g, &g->textures[20], g->menu_cont);
}

void		draw_sector_menu(t_env *env, t_graph *g, t_eflags *f)
{
	const t_pnt		mas[13] = { { 120, 360 }, { 210, 360 },
		{ 85, 475 }, { 165, 475 }, { 245, 475 },
		{ 30, 600 }, { 115, 600 }, { 215, 600 },
		{ 300, 600 }, { 30, 720 }, { 115, 720 },
		{ 215, 720 }, { 300, 720 } };
	int				i;
	int				active;

	if (f->sec.active > -1)
	{
		i = 17;
		active = -1;
		if (f->sec.object_btn > NO_OBJ)
			active = f->sec.object_btn - 13;
		while (++i <= 30)
		{
			if (i == active)
				surf_to_scr((t_xy) {mas[i - 18].x, mas[i - 18].y},
					g, &env->graph->menu[f->sec.object_btn], g->menu_cont);
			else
				surf_to_scr((t_xy) {mas[i - 18].x, mas[i - 18].y}, g,
					&env->graph->menu[i], g->menu_cont);
		}
		draw_arrows(g, f);
	}
}

void		try_draw_obj(t_inner *tmp_obj, t_graph *g, t_env *env)
{
	const int		x = CALC_X(tmp_obj->coord.x);
	const int		y = CALC_Y(tmp_obj->coord.y);

	if (TMPOBJ.x >= OFFSET_X && TMPOBJ.x <= WIREFRAME_W - ZOOM
		&& TMPOBJ.y >= OFFSET_Y && TMPOBJ.y <= WIREFRAME_H - ZOOM)
	{
		if (env->flags->player.err_msg && env->flags->player.status)
		{
			env->flags->player.err_msg = FALSE;
			show_error_message(3, env);
		}
		if (env->map.dot[y][x].sect_num != env->flags->sec.active
			|| env->map.dot[y][x].status != 1)
		{
			surf_to_scr((t_xy) {TMPOBJ.x - 10,
			TMPOBJ.y - 10}, g, &g->obj[0], g->menu_cont);
			show_error_message(4, env);
		}
		else
			surf_to_scr((t_xy) {TMPOBJ.x - 10, TMPOBJ.y - 10}, g,
				&g->obj[env->flags->sec.object_btn - 30], g->menu_cont);
	}
	else
		show_error_message(0, env);
}

void		try_to_draw(t_env *env)
{
	if (env->flags->curr_pos.x > OFFSET_X
		&& env->flags->curr_pos.y > OFFSET_Y
		&& env->flags->curr_pos.x < (MAP_X - 2) * ZOOM + OFFSET_X
		&& env->flags->curr_pos.y < (MAP_Y - 2) * ZOOM + OFFSET_Y)
	{
		if (env->flags->sec.type_btn != NONE && env->sdata.tmp_sec)
			try_draw_sector(env->sdata.tmp_sec, env->graph, env);
		else if (env->flags->sec.object_btn != NO_OBJ && env->sdata.tmp_obj)
			try_draw_obj(env->sdata.tmp_obj, env->graph, env);
	}
	else
		show_error_message(0, env);
}

void		draw_menu_main(t_env *env)
{
	size_t			y;
	size_t			x;

	y = UINT64_MAX;
	while (++y < WIN_HEIGHT)
	{
		x = UINT64_MAX;
		while (++x < 400)
			set_pixel(env->graph->screen_srf->pixels, (t_pnt){ x, y },
				env->graph->screen_srf->w, 0x212121);
	}
	draw_map(env->map, env->graph);
	draw_context(env->graph, env->flags);
	main_menu(env, env->graph, env->graph->menu, env->flags);
	draw_created_sectors(env);
	if (env->flags->sec.type_btn > -1 || env->flags->sec.object_btn > -1)
		try_to_draw(env);
}
