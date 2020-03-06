/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <dshpack@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:35:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/05/23 18:35:00 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void		event_arrows_handler_parameters(t_data *d, t_eflags *flags)
{
	if ((flags->mouse_pos.x >= 90 && flags->mouse_pos.x <= 122
		&& flags->mouse_pos.y >= 165 && flags->mouse_pos.y < 197
		&& (flags->l_mouse_down && (flags->arrow.w_l = ACTIVE_L)))
		|| (flags->mouse_pos.x >= 90 && flags->mouse_pos.x <= 122
		&& flags->mouse_pos.y >= 225 && flags->mouse_pos.y < 257
		&& (flags->l_mouse_down && (flags->arrow.h_l = ACTIVE_L))))
	{
		d->tmp_w > 3 ? d->tmp_w-- : d->tmp_w;
		d->tmp_h > 3 ? d->tmp_h-- : d->tmp_h;
	}
	else if ((flags->mouse_pos.x >= 278 && flags->mouse_pos.x <= 310
		&& flags->mouse_pos.y >= 165 && flags->mouse_pos.y < 197
		&& (flags->l_mouse_down && (flags->arrow.w_r = ACTIVE_R)))
		|| (flags->mouse_pos.x >= 278 && flags->mouse_pos.x <= 310
		&& flags->mouse_pos.y >= 225 && flags->mouse_pos.y < 257
		&& (flags->l_mouse_down && (flags->arrow.h_r = ACTIVE_R))))
	{
		d->tmp_w < 9 ? d->tmp_w++ : d->tmp_w;
		d->tmp_h < 9 ? d->tmp_h++ : d->tmp_h;
	}
}

void		event_handler(t_eflags *flags, t_elem *sec, t_env *env)
{
	sectors_worker(flags, sec, env, &(env->sdata.tmp_sec));
	if (flags->btn_delete && sec->active > NONE)
	{
		delete_sector(env->sdata.sec, sec->active, &env->sdata, &env->map);
		sec->create_sec = -1;
		flags->btn_delete = FALSE;
		sec->active = -1;
	}
	if (!flags->l_mouse_down && flags->game_start)
	{
		flags->game_start = FALSE;
		if (flags->player.status && env->sdata.cout > 0)
			;
		else
			show_error_message(2, env);
	}
}
