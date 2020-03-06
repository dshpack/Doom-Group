/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 18:51:52 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/28 18:51:53 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void	init_main_cycle(t_player *player, t_system *sys,
	SDL_Texture *game_texture)
{
	render_things(sys, game_texture);
	SDL_RenderClear(REND);
	SDL_RenderCopy(REND, game_texture, NULL, NULL);
	SDL_RenderCopy(REND, HUD.hud_texture, NULL, NULL);
	draw_skybox(sys);
	draw_screen(sys);
	sprite_casting(sys);
	hud_text(sys);
	move(player);
}

void	draw_screen(t_system *sys)
{
	int	renderedsectors[sys->num_sectors];

	draw_screen_init(sys, renderedsectors);
	SDL_LockSurface(FAKE);
	while (SDSC.head != SDSC.tail)
	{
		SDSC.now = *SDSC.tail;
		if (++SDSC.tail == SDSC.queue + MAX_QUEUE)
			SDSC.tail = SDSC.queue;
		if (renderedsectors[SDSC.now.sectorno] & 0x21)
			continue;
		++renderedsectors[SDSC.now.sectorno];
		include_in_drawscreen(sys);
		++renderedsectors[SDSC.now.sectorno];
	}
	SDL_UnlockSurface(FAKE);
}

void	main_cycle_sdl(t_system *sys, SDL_Texture *game_texture)
{
	SDL_UpdateTexture(game_texture, NULL, FAKE->pixels, FAKE->pitch);
	SDL_RenderPresent(REND);
	SDL_Delay(10);
}

int		game_play(t_system *sys)
{
	if (sys->map_i == 2)
	{
		if (sys->player->num_sect == 14)
		{
			if (SP->inv.yellow_key != 1)
				ft_putstr("GAME OVER");
			else
				ft_putstr("YOU WIN");
			return (2);
		}
	}
	if (sys->map_i == 1)
	{
		if (SP->num_sect == 14)
			SP->inv.yellow_key = 1;
		if (SP->inv.yellow_key == 1 && SP->num_sect == 0)
		{
			ft_putstr("YOU WIN");
			return (2);
		}
	}
	return (1);
}

void	main_cycle(t_player *player, t_system *sys, float yaw)
{
	float		eyeheight;
	SDL_Texture *game_texture;
	int			val;

	game_texture = SDL_CreateTextureFromSurface(REND, FAKE);
	load_things(sys);
	while (1)
	{
		init_main_cycle(player, sys, game_texture);
		pos_m(sys, player, &eyeheight);
		mouse_event(sys->player, sys, &yaw);
		val = key_event(sys);
		if (val != 0)
			break ;
		if (game_play(sys) == 2)
			break ;
		main_cycle_sdl(sys, game_texture);
	}
	free_main_cycle(game_texture, sys);
	done(sys);
}
