/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <dshpack@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 03:15:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/07/01 03:15:00 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

SDL_Surface	*load_editor_image(const char *filename)
{
	SDL_Surface			*loaded_image;
	SDL_Surface			*optimized_image;
	SDL_PixelFormat		px_fmt;

	px_fmt = (SDL_PixelFormat){ .format = SDL_PIXELFORMAT_ARGB8888,
			.palette = NULL,
			.BytesPerPixel = sizeof(Uint32),
			.BitsPerPixel = (Uint8)(sizeof(Uint32) * 8) };
	optimized_image = NULL;
	if ((loaded_image = IMG_Load(filename)))
	{
		optimized_image = SDL_ConvertSurface(loaded_image, &px_fmt, 0);
		SDL_FreeSurface(loaded_image);
	}
	return (optimized_image);
}

int			load_content(t_graph *graph)
{
	if (!(graph->menu_cont = load_editor_image("./menu/menu_content.png")))
		return (0);
	graph->screen_srf =
			SDL_CreateRGBSurface(SDL_SWSURFACE, WIN_WIDTH, WIN_HEIGHT, 32,
								0, 0, 0, 0);
	return (1);
}

int			init(t_graph *graph)
{
	if (!(graph->window = SDL_CreateWindow("- = Level Editor = -",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH,
		WIN_HEIGHT, SDL_WINDOW_SHOWN)))
	{
		log_sdl_error("SDL_CreateWindow Error");
		SDL_Quit();
		return (1);
	}
	else
		graph->renderer = SDL_CreateRenderer(graph->window, -1,
					SDL_RENDERER_PRESENTVSYNC);
	return (0);
}

void		init_main_variables(t_env **env)
{
	*env = (t_env *)malloc(sizeof(t_env));
	(*env)->graph = (t_graph *)malloc(sizeof(t_graph));
	(*env)->flags = (t_eflags *)malloc(sizeof(t_eflags));
}
