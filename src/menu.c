/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 12:11:17 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/28 12:11:19 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

int		event_menu(t_system *sys, t_player *player)
{
	SDL_Event ev;

	while (SDL_PollEvent(&ev))
	{
		if (ev.type == SDL_QUIT)
			return (1);
		if (IS_SDL_KD && KEY == SDLK_ESCAPE && MENU.flag == 1)
			MENU.flag = 0;
		else if (IS_SDL_KD && KEY == SDLK_ESCAPE)
			return (1);
		event_menu2(sys, player, ev);
		if (IS_SDL_KD && KEY == SDLK_RETURN && MENU.menu_nb == 0)
			MENU.flag = 1;
		if (IS_SDL_KD && KEY == SDLK_RETURN && MENU.menu_nb == 1)
			MENU.flag = 3;
		else if (IS_SDL_KD && KEY == SDLK_RETURN && MENU.menu_nb == 2
			&& MENU.flag != 1)
			return (1);
	}
	return (0);
}

int		event_menu2(t_system *sys, t_player *player, SDL_Event ev)
{
	if (IS_SDL_KD && (KEY == SDLK_UP) && MENU.menu_nb > 0)
	{
		MENU.menu_nb--;
		return (2);
	}
	else if (IS_SDL_KD && (KEY == SDLK_DOWN) && MENU.menu_nb < 2)
	{
		MENU.menu_nb++;
		return (2);
	}
	else if (event_help(sys, ev, player) == 1)
		return (1);
	return (0);
}

void	menu_text(t_system *sys)
{
	if (MENU.flag == 0)
	{
		MENU.str[0] = "LEVELS";
		MENU.str[1] = "MAP EDITOR";
		MENU.str[2] = "EXIT";
	}
	if (MENU.flag == 1)
	{
		MENU.str[0] = "LEVEL 1";
		MENU.str[1] = "LEVEL 2";
		MENU.str[2] = "LEVEL BONUS";
	}
}

void	hud_text2(t_system *sys, char *buff)
{
	draw_text(sys, "x: ", set_txt(55, 735, HUD.hud_color, 10));
	buff = ft_itoa((int)sys->player->where.x);
	draw_text(sys, buff, set_txt(75, 735, HUD.hud_color, 10));
	ft_strdel(&buff);
	draw_text(sys, "y: ", set_txt(55, 710, HUD.hud_color, 10));
	buff = ft_itoa((int)sys->player->where.y);
	draw_text(sys, buff, set_txt(75, 710, HUD.hud_color, 10));
	ft_strdel(&buff);
	draw_text(sys, "z: ", set_txt(55, 760, HUD.hud_color, 10));
	buff = ft_itoa((int)sys->player->where.z);
	draw_text(sys, buff, set_txt(75, 760, HUD.hud_color, 10));
	ft_strdel(&buff);
	draw_text(sys, "sect: ", set_txt(175, 710, HUD.hud_color, 10));
	buff = ft_itoa((int)sys->player->num_sect);
	draw_text(sys, buff, set_txt(195, 710, HUD.hud_color, 10));
	ft_strdel(&buff);
	draw_text(sys, "INV: ", set_txt(175, 760, HUD.hud_color, 10));
	buff = ft_itoa((int)sys->player->inv.yellow_key);
	draw_text(sys, buff, set_txt(195, 760, HUD.hud_color, 10));
	ft_strdel(&buff);
}

void	hud_text(t_system *sys)
{
	char		*buff;

	HUD.hud_color.r = 255;
	HUD.hud_color.g = 255;
	HUD.hud_color.b = 255;
	draw_text(sys, "AMMO:", set_txt(1150, 620, HUD.hud_color, 10));
	buff = ft_itoa((int)SP->ammo);
	draw_text(sys, buff, set_txt(1220, 620, HUD.hud_color, 10));
	ft_strdel(&buff);
	draw_text(sys, "HEALTH:", set_txt(1160, 680, HUD.hud_color, 10));
	buff = ft_itoa((int)SP->health);
	draw_text(sys, buff, set_txt(1240, 680, HUD.hud_color, 10));
	ft_strdel(&buff);
	draw_text(sys, "WHATEVER:", set_txt(1190, 750, HUD.hud_color, 10));
	ft_strdel(&buff);
	draw_text(sys, "Write your message here",
		set_txt(650, 710, HUD.hud_color, 10));
	hud_text2(sys, buff);
}
