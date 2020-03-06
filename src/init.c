/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 17:53:53 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/28 17:53:54 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void			init_player(t_player *player)
{
	PP.wsad[0] = 0;
	PP.wsad[1] = 0;
	PP.wsad[2] = 0;
	PP.wsad[3] = 0;
	PP.ground = 0;
	PP.falling = 1;
	PP.flying = 0;
	PP.moving = 0;
	PP.ducking = 0;
	PP.map = 0;
	player->ammo = 30;
	player->health = 100;
}

void			restore_params(t_eflags *flags)
{
	flags->arrow.w_l = NOT_ACTIVE_L;
	flags->arrow.w_r = NOT_ACTIVE_R;
	flags->arrow.h_l = NOT_ACTIVE_L;
	flags->arrow.h_r = NOT_ACTIVE_R;
}

void			init_variables(t_env *env)
{
	env->flags->running = 1;
	env->flags->btn_space = 0;
	init_map(&env->map);
	env->flags->sec.type_btn = NONE;
	env->sdata.cout = 0;
	env->map.wall_nb = 0;
	env->map.sector_shape = 0;
	env->flags->sec.active = -1;
	env->flags->game_start = FALSE;
	env->flags->sec.create_sec = FALSE;
	env->flags->sec.create_obj = FALSE;
	env->flags->btn_delete = FALSE;
	env->flags->player.status = FALSE;
	env->flags->player.err_msg = FALSE;
	env->flags->sec.object_btn = NO_OBJ;
	env->sdata.store_size = 42;
	env->sdata.sec = recreate_sector_storage(42, 0, NULL);
	env->sdata.cout = 0;
	env->flags->on_pos = NONE;
	env->sdata.tmp_w = 3;
	env->sdata.tmp_h = 3;
	env->sdata.tmp_type = NONE;
	env->sdata.tmp_sec = NULL;
	prepare_menu_cont(env->graph);
}

void			init_window(t_system *sys)
{
	TTF_Init();
	IMG_Init(IMG_INIT_PNG);
	SDL_Init(SDL_INIT_EVERYTHING);
	SW = SDL_CreateWindow("Doom_Nukem",
						SDL_WINDOWPOS_CENTERED,
						SDL_WINDOWPOS_CENTERED, W, H, 0);
	sys->renderer = SDL_CreateRenderer(sys->window, -1,
										SDL_RENDERER_PRESENTVSYNC);
	sys->texture = SDL_CreateTexture(sys->renderer,
										SDL_PIXELFORMAT_ARGB8888,
										SDL_TEXTUREACCESS_TARGET, W, H);
	sys->surface = SDL_GetWindowSurface(SW);
	sys->fake_surface = SDL_CreateRGBSurface(0, W, H, 32, 0, 0, 0, 0);
	sys->font_ttf = TTF_OpenFont("./fonts/SAOUITT-Bold.TTF", 24);
	if (sys->font_ttf == NULL)
	{
		ft_putendl("error: font not found\n");
		exit(EXIT_FAILURE);
	}
}

t_system		*init_system(void)
{
	t_system	*sys;

	if (!(sys = ft_memalloc(sizeof(t_system))))
		print_error("Can't allocate memory");
	if (sys)
	{
		sys->wh.w = W;
		sys->wh.h = H;
		sys->num_sectors = 0;
		sys->sectors = NULL;
		sys->player = (t_player*)malloc(sizeof(t_player));
		MENU.menu_nb = 0;
		MENU.flag = 0;
		MENU.menu = load_image("./menu/menu.png");
	}
	return (sys);
}
