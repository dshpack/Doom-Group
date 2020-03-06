/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <dshpack@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:57:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/04/10 18:57:00 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void			mousev(t_env *env, t_eflags *flags)
{
	if (env->map.dot[CALC_Y(FMP.y)][CALC_X(FMP.x)].status > -1 &&
		flags->sec.type_btn == -1 && flags->sec.object_btn == -1)
		flags->sec.active = env->map.dot[CALC_Y(FMP.y)][CALC_X(FMP.x)]
				.sect_num;
	else if (flags->sec.type_btn > -1 && flags->sec.object_btn == -1 &&
	flags->sec.active == -1)
		flags->sec.create_sec = TRUE;
	else if (flags->sec.type_btn == -1 && flags->sec.object_btn > -1 &&
	flags->sec.active > -1)
		flags->sec.create_obj = TRUE;
}

void			mouse_mot(SDL_Event event, t_eflags *flags)
{
	if (event.type == SDL_MOUSEMOTION)
	{
		flags->curr_pos.x = event.motion.x;
		flags->curr_pos.y = event.motion.y;
		check_mouse_pos(flags->curr_pos.x, flags->curr_pos.y, &flags->on_pos);
	}
	if (event.type == SDL_MOUSEBUTTONUP)
	{
		if (event.button.button == SDL_BUTTON_LEFT)
			flags->l_mouse_down = FALSE;
	}
}

void			mous_e(t_env *env, t_eflags *flags)
{
	if (FMP.x >= 20 && FMP.x <= 380 &&
		FMP.y >= 65 && FMP.y <= 135)
		find_choosen_sector_type(FMP.x, FMP.y,
	&flags->sec.type_btn, &flags->sec.active);
	else if (FMP.x <= WIREFRAME_W && FMP.y <= WIREFRAME_H &&
	FMP.x >= OFFSET_X && FMP.y >= OFFSET_Y)
		mousev(env, flags);
	else if (flags->sec.type_btn == NONE &&
	flags->sec.active > -1 && FMP.x >= 30 &&
	FMP.x <= 370 && FMP.y >= 360 && FMP.y <= 790)
		find_choosen_object(FMP.x, FMP.y, &flags->sec.object_btn);
	else if (FMP.x >= 130 && FMP.x <= 273 &&
	FMP.y >= 1120 && FMP.y <= 1173)
		flags->game_start = TRUE;
	else
		flags->sec.active = -1;
}

static void		mouse_evnt(t_env *env, SDL_Event event, t_eflags *flags)
{
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			FMP.x = event.motion.x;
			FMP.y = event.motion.y;
			flags->l_mouse_down = TRUE;
			mous_e(env, flags);
			event_arrows_handler_parameters(&env->sdata, flags);
		}
	}
	mouse_mot(event, flags);
}

void			event_listener(t_eflags *flags, t_env *env)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			flags->running = 0;
		if (event.type == SDL_WINDOWEVENT)
			if (event.window.event == SDL_WINDOWEVENT_CLOSE)
				if (SDL_GetWindowID(env->graph->window) ==
				event.window.windowID)
					flags->running = 0;
		mouse_evnt(env, event, flags);
		keyboard_event(event, event.key.keysym.sym, flags);
	}
}
