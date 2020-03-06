/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 12:31:01 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/28 12:31:03 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void			draw_text(t_system *sys, char *text, t_text txt)
{
	SDL_Surface	*surf;
	SDL_Texture	*texture;
	SDL_Rect	dest;

	TTF_SizeText(sys->font_ttf, text, &dest.w, &dest.h);
	surf = TTF_RenderText_Solid(sys->font_ttf, text, txt.color);
	texture = SDL_CreateTextureFromSurface(REND, surf);
	dest.x = txt.pos.x - (dest.w >> 1);
	dest.y = txt.pos.y;
	SDL_RenderCopy(REND, texture, NULL, &dest);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surf);
}

void			draw_lines(t_system *sys)
{
	int q;

	q = -1;
	menu_text(sys);
	while (++q != 3)
	{
		MENU.menu_color.r = 255;
		MENU.menu_color.g = 255;
		MENU.menu_color.b = 255;
		if (q == MENU.menu_nb)
		{
			MENU.menu_color.r = 153;
			MENU.menu_color.g = 0;
			MENU.menu_color.b = 0;
		}
		draw_text(sys, MENU.str[q], set_txt(W / 2, 100 + (q * 50),
												MENU.menu_color, 110));
	}
}

t_text			set_txt(int x, int y, SDL_Color color, int font_size)
{
	t_text res;

	res.pos.x = x;
	res.pos.y = y;
	res.color = color;
	res.size = font_size;
	return (res);
}

SDL_Surface		*load_image(char *path)
{
	SDL_Surface *surface;

	surface = IMG_Load(path);
	if (surface == NULL)
		print_error("Bad load image");
	return (surface);
}

void			load_music(t_system *sys)
{
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048) < 0 ||
		!(sys->music = Mix_LoadMUS("./music/carpenter.wav")))
	{
		ft_putendl((char *)SDL_GetError());
		exit(2);
	}
	Mix_VolumeMusic(10);
}
