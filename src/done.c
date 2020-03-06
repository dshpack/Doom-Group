/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   done.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 19:59:41 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/28 19:59:42 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void		free_main_cycle(SDL_Texture *game_texture, t_system *sys)
{
	Mix_FreeMusic(sys->music);
	SDL_FreeSurface(HUD.hud_surf);
	SDL_DestroyTexture(HUD.hud_texture);
	SDL_DestroyTexture(game_texture);
}

void		unload_tex(t_texture **tex)
{
	int		i;

	i = -1;
	while (++i < 8)
	{
		free(tex[i]);
	}
}

int			done(t_system *sys)
{
	ft_memdel((void **)&sys->map);
	SDL_DestroyTexture(sys->texture);
	SDL_FreeSurface(sys->menu.menu);
	ft_memdel((void**)&sys->player);
	SDL_DestroyWindow(sys->window);
	SDL_FreeSurface(sys->surface);
	SDL_FreeSurface(sys->fake_surface);
	TTF_CloseFont(sys->font_ttf);
	SDL_DestroyRenderer(sys->renderer);
	ft_memdel((void **)&(sys->map));
	ft_memdel((void **)&sys);
	TTF_Quit();
	exit(0);
}
