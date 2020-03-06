/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <osak@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:06:43 by osak              #+#    #+#             */
/*   Updated: 2019/06/10 20:06:44 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void	event_init(t_system *sys, t_player *player, SDL_Event ev)
{
	(void)sys;
	KEY == SDLK_w ? PP.wsad[0] = ev.type == SDL_KEYDOWN : 0;
	KEY == SDLK_s ? PP.wsad[1] = ev.type == SDL_KEYDOWN : 0;
	KEY == SDLK_a ? PP.wsad[2] = ev.type == SDL_KEYDOWN : 0;
	KEY == SDLK_d ? PP.wsad[3] = ev.type == SDL_KEYDOWN : 0;
}

void	key_event2(t_system *sys, SDL_Event ev)
{
	if (KEY == SDLK_LCTRL || KEY == SDLK_RCTRL)
	{
		sys->PP.ducking = ev.type == SDL_KEYDOWN;
		sys->PP.falling = 1;
	}
	if (KEY == SDLK_e)
	{
		sys->player->velocity.z += 0.1;
		sys->player->pos.falling = 1;
	}
}

int		key_event(t_system *sys)
{
	SDL_Event	ev;

	while (SDL_PollEvent(&ev))
	{
		if (ev.type == SDL_KEYDOWN && KEY == SDLK_ESCAPE)
			return (2);
		event_init(sys, sys->player, ev);
		if (KEY == SDLK_SPACE)
			if (sys->PP.ground == 1)
			{
				sys->player->velocity.z += 0.5;
				sys->PP.falling = 1;
			}
		key_event2(sys, ev);
		if (ev.type == SDL_QUIT)
			return (1);
	}
	return (0);
}

void	result(float *move_vec, t_player *player)
{
	if (PP.wsad[0] != 0)
	{
		move_vec[0] += player->anglecos * 0.2f;
		move_vec[1] += player->anglesin * 0.2f;
	}
	if (PP.wsad[1] != 0)
	{
		move_vec[0] -= player->anglecos * 0.2f;
		move_vec[1] -= player->anglesin * 0.2f;
	}
	if (PP.wsad[2] != 0)
	{
		move_vec[0] += player->anglesin * 0.2f;
		move_vec[1] -= player->anglecos * 0.2f;
	}
	if (PP.wsad[3] != 0)
	{
		move_vec[0] -= player->anglesin * 0.2f;
		move_vec[1] += player->anglecos * 0.2f;
	}
}

void	move(t_player *player)
{
	int		pushing;
	float	move_vec[2];
	float	acceleration;

	move_vec[0] = 0.f;
	move_vec[1] = 0.f;
	result(move_vec, player);
	if (PP.wsad[0])
		pushing = 1;
	else
		pushing = PP.wsad[1] != 0 || PP.wsad[2] || PP.wsad[3];
	acceleration = pushing ? 0.4 : 0.2;
	player->velocity.x = player->velocity.x * (1 - acceleration)
			+ move_vec[0] * acceleration;
	player->velocity.y = player->velocity.y * (1 - acceleration)
			+ move_vec[1] * acceleration;
	if (pushing)
		PP.moving = 1;
}
