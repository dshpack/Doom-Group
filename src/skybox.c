/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 17:31:43 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/28 17:31:45 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

#define S_W 3600
#define S_H 2700

void		skybox_vline(t_system *sys, int x, int start_x)
{
	int y;
	int y1;

	y = 0;
	y1 = 871 + (int)(SP->yaw * 94);
	while (y < H)
	{
		if (y1 < S_H && start_x < S_W)
			((int*)FAKE->pixels)[y * W2 + x] = sys->surface_box[y1][start_x];
		else
			((int*)FAKE->pixels)[y * W2 + x] = 0x5d5f63;
		y1++;
		y++;
	}
}

void		draw_skybox(t_system *sys)
{
	int x;
	int st_x;

	x = 0;
	if (SP->anglesin <= 0)
		st_x = (int)(SP->anglecos / (2 / 360.0) *
						((double)S_W / 2 / 360.0));
	else
		st_x = (int)(S_W / 2 - (SP->anglecos / (2 / 360.0)
									* ((double)S_W / 2 / 360.0)));
	if (st_x < 0)
		st_x = S_W + st_x;
	while (x < W)
	{
		st_x++;
		if (st_x < 0)
			st_x = S_W;
		if (st_x > S_W)
			st_x = 0;
		skybox_vline(sys, x, st_x);
		x++;
	}
}

void		load_surface_skybox(t_system *sys, SDL_Surface *sky_box)
{
	int				x;
	int				y;
	unsigned int	*pixels;

	pixels = (unsigned int *)sky_box->pixels;
	y = -1;
	while (++y < S_H)
	{
		sys->surface_box[y] = (int *)malloc(sizeof(int) * S_W);
		x = -1;
		while (++x < S_W)
			sys->surface_box[y][x] = pixels[(y * sky_box->w) + x];
	}
}

int			load_skybox(t_system *sys)
{
	SDL_Surface		*sky_box;

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		ft_putendl(IMG_GetError());
	sky_box = IMG_Load("./assets/barrel.png");
	if (!sky_box)
	{
		ft_putendl("Img_Load:");
		ft_putendl(IMG_GetError());
		return (-1);
	}
	sys->surface_box = (int **)malloc(sizeof(int *) * S_H);
	load_surface_skybox(sys, sky_box);
	SDL_FreeSurface(sky_box);
	return (1);
}
