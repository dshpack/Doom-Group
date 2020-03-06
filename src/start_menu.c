/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 04:20:11 by olaktion          #+#    #+#             */
/*   Updated: 2019/07/01 04:20:15 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void	start_menu1(t_system *sys)
{
	SDL_HideWindow(sys->window);
	SDL_ShowCursor(SDL_ENABLE);
	start_lvl_editor();
	SDL_ShowWindow(sys->window);
	SDL_ShowCursor(SDL_DISABLE);
	sys->menu.flag = 0;
}

void	start_menu2(t_system *sys)
{
	SDL_RenderCopy(REND, sys->texture, NULL, NULL);
	draw_lines(sys);
	SDL_RenderPresent(REND);
}

int		start_menu(void)
{
	t_system	*sys;

	sys = init_system();
	init_window(sys);
	init_player(SP);
	load_music(sys);
	sys->texture = SDL_CreateTextureFromSurface(REND, MENU.menu);
	sys->menu.menu_status = 2;
	Mix_PlayMusic(sys->music, 10);
	SDL_ShowCursor(SDL_DISABLE);
	while (1)
	{
		if (sys->menu.flag == 3)
			start_menu1(sys);
		if (sys->menu.menu_status == 1)
			break ;
		else
			start_menu2(sys);
		sys->menu.menu_status = event_menu(sys, sys->player);
	}
	done(sys);
	return (0);
}
