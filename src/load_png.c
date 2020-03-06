/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_png.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 17:23:01 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/28 17:23:03 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void		create_tex(t_texture **texture)
{
	int		i;

	i = -1;
	while (++i < 8)
	{
		texture[i] = malloc(sizeof(*texture[i]));
		if (i <= 2)
			load_textures("./assets/glass.png", texture[i]);
		else if (2 < i && i <= 4)
			load_textures("./assets/glass.png", texture[i]);
		else
			load_textures("./assets/planks_jungle.png", texture[i]);
	}
}

void		load_textures(char *string, t_texture *tex)
{
	SDL_Surface		*image;
	unsigned int	*pixelss;
	int				i;
	int				j;

	image = IMG_Load(string);
	if (!image)
	{
		ft_putendl("IMG_Load:");
		ft_putendl(IMG_GetError());
	}
	else
	{
		pixelss = (unsigned int*)image->pixels;
		i = -1;
		while (++i < image->h)
		{
			j = -1;
			while (++j < image->w)
				tex->texture[j][i] = pixelss[i + (j * image->w)];
		}
	}
	SDL_FreeSurface(image);
}

int			upload_items(t_system *sys, int key, char *string)
{
	SDL_Surface		*sprite;
	unsigned int	*pixels;
	int				x;
	int				y;

	sprite = IMG_Load(string);
	if (!sprite)
	{
		ft_putendl("IMG_Load:");
		ft_putendl(IMG_GetError());
		return (-1);
	}
	sys->dscreen.card[key] = (int**)malloc(sizeof(int *) * SPR_H);
	pixels = (unsigned int *)sprite->pixels;
	y = -1;
	while (++y < SPR_H)
	{
		x = -1;
		sys->dscreen.card[key][y] = (int *)malloc(sizeof(int) * SPR_W);
		while (++x < SPR_W)
			sys->dscreen.card[key][y][x] = pixels[(y * sprite->w) + x];
	}
	SDL_FreeSurface(sprite);
	return (0);
}

int			load_items(t_system *system)
{
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		ft_putendl(IMG_GetError());
	system->dscreen.card = (int***)malloc(sizeof(int **) * 3);
	upload_items(system, YELLOW_KEY, "assets/yellow_k.png");
	upload_items(system, RED_KEY, "assets/yellow_k.png");
	upload_items(system, GREEN_KEY, "assets/green_k.png");
	return (1);
}
