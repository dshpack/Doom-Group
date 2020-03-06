/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_tools2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <osak@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 04:00:39 by osak              #+#    #+#             */
/*   Updated: 2019/07/01 04:00:41 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void		set_pixel(int *buffer, t_pnt coords, int width, Uint32 color)
{
	buffer[coords.y * width + coords.x] = color;
}

char		*write_text(t_ttf_p text, t_graph *graph)
{
	TTF_Font	*fnt;

	fnt = TTF_OpenFont("./fonts/PTS55F.ttf", text.size);
	graph->mouse_text = TTF_RenderText_Blended(fnt, text.line, text.color);
	SDL_BlitSurface(graph->mouse_text, NULL, graph->screen_srf,
			&((SDL_Rect){text.pos.x, text.pos.y, 0, 0}));
	SDL_FreeSurface(graph->mouse_text);
	TTF_CloseFont(fnt);
	return (text.line);
}
