/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <osak@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:11:39 by osak              #+#    #+#             */
/*   Updated: 2019/06/10 18:11:42 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void	load_things(t_system *sys)
{
	HUD.hud_surf = load_image("./menu/hud31.png");
	HUD.hud_texture = SDL_CreateTextureFromSurface(REND, HUD.hud_surf);
	Mix_PlayMusic(sys->music, -1);
}

void	render_things(t_system *sys, SDL_Texture *game_texture)
{
	SDL_RenderClear(REND);
	SDL_RenderCopy(REND, game_texture, NULL, NULL);
	SDL_RenderCopy(REND, HUD.hud_texture, NULL, NULL);
}

void	mouse_event(t_player *player, t_system *sys, float *yaw)
{
	int		x;
	int		y;

	SDL_GetRelativeMouseState(&x, &y);
	SDL_SetRelativeMouseMode(SDL_TRUE);
	player->angle += x * 0.03f;
	*yaw = CLAMP(*yaw + y * 0.05f, -5, 5);
	player->yaw = *yaw - PV.z * 0.5f;
	move_player(player, SS, (t_xy){0, 0});
}
