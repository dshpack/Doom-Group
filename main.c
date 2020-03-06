/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 06:07:37 by olaktion          #+#    #+#             */
/*   Updated: 2019/07/01 06:07:38 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

int				go(t_system *sys, t_player *player)
{
	read_file(sys);
	load_texture(sys);
	load_skybox(sys);
	load_items(sys);
	main_cycle(player, sys, 0);
	return (1);
}

int				event_help(t_system *sys, SDL_Event ev, t_player *player)
{
	if (IS_SDL_KD && KEY == SDLK_RETURN && MENU.menu_nb == 0 && MENU.flag == 1)
	{
		sys->map = ft_strdup("tower.txt");
		sys->map_i = 1;
		if (go(sys, player) == 1)
			return (1);
	}
	else if (KEY == SDLK_RETURN && MENU.menu_nb == 1 && MENU.flag == 1)
	{
		sys->map_i = 2;
		sys->map = ft_strdup("long_map.txt");
		if (go(sys, player) == 1)
			return (1);
	}
	else if (KEY == SDLK_RETURN && MENU.menu_nb == 2 && MENU.flag == 1)
	{
		sys->map = ft_strdup("bonus_level.txt");
		if (go(sys, player) == 1)
			return (1);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	if (argc == 2 && !ft_strcmp(argv[1], "menu"))
		start_menu();
	else
		ft_putstr_fd("usage: ./doom-nukem menu \n", 1);
	return (0);
}
