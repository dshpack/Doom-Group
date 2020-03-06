/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_visualizer3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <dshpack@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:45:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/05/22 18:45:00 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

Uint32		tds_helper(t_sect *s, t_env *env, t_sec_rect f)
{
	Uint32		color;

	if (f.second.x > WIREFRAME_W || f.second.y > WIREFRAME_H
		|| f.second.x < OFFSET_X || f.second.y < OFFSET_Y
		|| f.first.x > WIREFRAME_W || f.first.y > WIREFRAME_H
		|| f.first.x < OFFSET_X || f.first.y < OFFSET_Y
		|| f.third.x > WIREFRAME_W || f.third.y > WIREFRAME_H
		|| f.third.x < OFFSET_X
		|| f.third.y < OFFSET_Y || is_place_occupied(s, env->map)
		|| (s->type == RECTANGLE && (f.fourth.x > WIREFRAME_W
		|| f.fourth.y > WIREFRAME_H || f.fourth.x < OFFSET_X
		|| f.fourth.y < OFFSET_Y)))
		color = 0xff0000;
	else
		color = 0x00FF7F;
	return (color);
}

void		try_draw_sector(t_sect *s, t_graph *graph, t_env *env)
{
	t_sec_rect	f;
	Uint32		color;

	f = s->figure;
	color = tds_helper(s, env, f);
	if (s->type == RECTANGLE)
		draw_rect(env->graph->screen_srf, s->figure, color);
	else if (s->type == TRIANGLE_DOWN_R)
		draw_triangle_down_r(graph->screen_srf, s->figure, color);
	else if (s->type == TRIANGLE_DOWN_L)
		draw_triangle_down_l(graph->screen_srf, s->figure, color);
	else if (s->type == TRIANGLE_UP_R)
		draw_triangle_right(graph->screen_srf, s->figure, color);
	else if (s->type == TRIANGLE_UP_L)
		draw_triangle_left(graph->screen_srf, s->figure, color);
	if (color == 0xff0000)
		show_error_message(1, env);
}

void		surf_to_scr(t_xy xy, t_graph *graph, SDL_Rect *clip,
															SDL_Surface *icon)
{
	SDL_BlitSurface(icon, clip, graph->screen_srf,
		&((SDL_Rect){xy.x, xy.y, 0, 0}));
	graph->texture = SDL_CreateTextureFromSurface(graph->renderer,
		graph->screen_srf);
	SDL_RenderCopy(graph->renderer, graph->texture, NULL, NULL);
	SDL_DestroyTexture(graph->texture);
}

void		sectors_btns(t_graph *g, SDL_Rect *menu, t_eflags *f)
{
	if (f->on_pos == RECTANGLE || f->sec.type_btn == RECTANGLE)
		surf_to_scr((t_xy){30, 65}, g, &menu[9], g->menu_cont);
	else
		surf_to_scr((t_xy){30, 65}, g, &menu[8], g->menu_cont);
	if (f->on_pos == TRIANGLE_DOWN_R || f->sec.type_btn == TRIANGLE_DOWN_R)
		surf_to_scr((t_xy){100, 65}, g, &menu[11], g->menu_cont);
	else
		surf_to_scr((t_xy){100, 65}, g, &menu[10], g->menu_cont);
	if (f->on_pos == TRIANGLE_DOWN_L || f->sec.type_btn == TRIANGLE_DOWN_L)
		surf_to_scr((t_xy){170, 65}, g, &menu[13], g->menu_cont);
	else
		surf_to_scr((t_xy){170, 65}, g, &menu[12], g->menu_cont);
	if (f->on_pos == TRIANGLE_UP_R || f->sec.type_btn == TRIANGLE_UP_R)
		surf_to_scr((t_xy){240, 65}, g, &menu[15], g->menu_cont);
	else
		surf_to_scr((t_xy){240, 65}, g, &menu[14], g->menu_cont);
	if (f->on_pos == TRIANGLE_UP_L || f->sec.type_btn == TRIANGLE_UP_L)
		surf_to_scr((t_xy){310, 65}, g, &menu[17], g->menu_cont);
	else
		surf_to_scr((t_xy){310, 65}, g, &menu[16], g->menu_cont);
}

void		main_menu(t_env *env, t_graph *g, SDL_Rect *menu, t_eflags *f)
{
	surf_to_scr((t_xy){90, 165}, g, &menu[f->arrow.w_l], g->menu_cont);
	surf_to_scr((t_xy){278, 165}, g, &menu[f->arrow.w_r], g->menu_cont);
	surf_to_scr((t_xy){90, 225}, g, &menu[f->arrow.h_l], g->menu_cont);
	surf_to_scr((t_xy){278, 225}, g, &menu[f->arrow.h_r], g->menu_cont);
	sectors_btns(g, menu, f);
	surf_to_scr((t_xy){130, 165}, g, &menu[5], g->menu_cont);
	surf_to_scr((t_xy){130, 225}, g, &menu[5], g->menu_cont);
	free(write_text((t_ttf_p){
			ft_itoa(env->sdata.tmp_w),
			(SDL_Color){255, 255, 255, 255}, (t_pnt){ 195, 165 }, 22
	}, env->graph));
	free(write_text((t_ttf_p){
			ft_itoa(env->sdata.tmp_h),
			(SDL_Color){255, 255, 255, 255}, (t_pnt){ 195, 225 }, 22
	}, env->graph));
	draw_sector_menu(env, env->graph, env->flags);
	if (!f->game_start)
		surf_to_scr((t_xy){130, 1120}, g, &g->btn_start[0], g->menu_cont);
	else
		surf_to_scr((t_xy){130, 1120}, g, &g->btn_start[1], g->menu_cont);
}
