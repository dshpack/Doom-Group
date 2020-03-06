/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl_editor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 02:13:59 by osak              #+#    #+#             */
/*   Updated: 2019/07/01 02:13:59 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void		close_program(t_graph *graph)
{
	SDL_DestroyTexture(graph->texture);
	SDL_DestroyRenderer(graph->renderer);
	SDL_DestroyWindow(graph->window);
	free(graph);
}

void		log_sdl_error(const char *msg)
{
	SDL_Log("%s%s\n", msg, SDL_GetError());
}

void		apply_surface(t_graph *graph)
{
	graph->texture =
			SDL_CreateTextureFromSurface(graph->renderer, graph->screen_srf);
	SDL_RenderCopy(graph->renderer, graph->texture, NULL, NULL);
	SDL_DestroyTexture(graph->texture);
}

void		clear_surface_scr(SDL_Surface *screen)
{
	size_t			y;
	size_t			x;

	y = UINT64_MAX;
	while (++y < WIN_HEIGHT)
	{
		x = UINT64_MAX;
		while (++x < WIN_WIDTH)
			set_pixel(screen->pixels, (t_pnt){ x, y }, screen->w, 0x0);
	}
}

int			start_lvl_editor(void)
{
	t_env			*env;

	init_main_variables(&env);
	init(env->graph);
	init_variables(env);
	if (!(load_content(env->graph)))
		exit(0);
	while (env->flags->running)
	{
		restore_params(env->flags);
		event_listener(env->flags, env);
		event_handler(env->flags, &env->flags->sec, env);
		SDL_RenderClear(env->graph->renderer);
		draw_menu_main(env);
		apply_surface(env->graph);
		SDL_RenderPresent(env->graph->renderer);
		clear_surface_scr(env->graph->screen_srf);
	}
	close_program(env->graph);
	return (0);
}
