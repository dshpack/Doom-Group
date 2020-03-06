/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_visualizer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <dshpack@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:45:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/05/22 18:45:00 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void		show_error_message(int key, t_env *env)
{
	if (key == 0)
		write_text((t_ttf_p){ "Move cursor to wireframe!",
			(SDL_Color){255, 0, 0, 0}, (t_pnt){495, 1165}, 17}, env->graph);
	else if (key == 1)
		write_text((t_ttf_p){ "Wrong space to put sector!",
			(SDL_Color){255, 0, 0, 0}, (t_pnt){495, 1165}, 17}, env->graph);
	else if (key == 2)
		write_text((t_ttf_p){ "It is impossible to start the game. "
			"You need to create at least one sector and place a player on it!",
			(SDL_Color){255, 0, 0, 0}, (t_pnt){495, 1165}, 17}, env->graph);
	else if (key == 3)
		write_text((t_ttf_p){ "Only one player can be create!",
			(SDL_Color){255, 0, 0, 0}, (t_pnt){495, 1165}, 17}, env->graph);
	else if (key == 4)
		write_text((t_ttf_p){
			"Bad place to put object!", (SDL_Color){255, 0, 0, 0},
			(t_pnt){495, 1165}, 17}, env->graph);
}

void		draw_context1(t_graph *g, SDL_Color usual)
{
	write_text((t_ttf_p){"SECTOR OBJECTS:", usual, (t_pnt){125, 280}, 20},
		g);
	write_text((t_ttf_p){"Player", usual, (t_pnt){135, 330}, 15},
		g);
	write_text((t_ttf_p){"Enemy", usual, (t_pnt){222, 330}, 15},
		g);
	write_text((t_ttf_p){"Start", usual, (t_pnt){105, 445}, 15},
		g);
	write_text((t_ttf_p){"Stairway", usual, (t_pnt){175, 445}, 15},
		g);
	write_text((t_ttf_p){"Finish", usual, (t_pnt){260, 445}, 15},
		g);
	write_text((t_ttf_p){"Health", usual, (t_pnt){45, 570}, 15},
		g);
	write_text((t_ttf_p){"Armored shell", usual, (t_pnt){105, 570}, 15},
		g);
	write_text((t_ttf_p){"Body armor", usual, (t_pnt){213, 570}, 15},
		g);
	write_text((t_ttf_p){"Helmet", usual, (t_pnt){310, 570}, 15},
		g);
	write_text((t_ttf_p){"Gun", usual, (t_pnt){55, 690}, 15},
		g);
	write_text((t_ttf_p){"Machine Gun", usual, (t_pnt){107, 690}, 15},
		g);
}

void		draw_context(t_graph *g, t_eflags *f)
{
	SDL_Color		usual;

	usual = (SDL_Color){255, 255, 255, 0};
	if (f->sec.active > -1)
	{
		draw_context1(g, usual);
		write_text((t_ttf_p){"Bullets", usual, (t_pnt){227, 690}, 15},
			g);
		write_text((t_ttf_p){"Magazine", usual, (t_pnt){300, 690}, 15},
			g);
		write_text((t_ttf_p){"CHOOSE TEXTURES", usual, (t_pnt){135, 790}, 15},
			g);
		write_text((t_ttf_p){"Floor:", usual, (t_pnt){82, 820}, 15},
			g);
		write_text((t_ttf_p){"Ceiling:", usual, (t_pnt){277, 820}, 15},
			g);
		write_text((t_ttf_p){"Walls:", usual, (t_pnt){180, 980}, 15},
			g);
	}
	write_text((t_ttf_p){"sector width:", usual, (t_pnt){160, 140}, 15}, g);
	write_text((t_ttf_p){"sector height:", usual, (t_pnt){160, 200}, 15}, g);
	write_text((t_ttf_p){"CHOOSE SECTOR TYPE:", usual, (t_pnt){100, 20}, 20},
		g);
	write_text((t_ttf_p){"Tips:", usual, (t_pnt){ OFFSET_X, 1165}, 17}, g);
}

void		draw_map(t_map map, t_graph *graph)
{
	size_t		y;
	size_t		x;

	y = UINT64_MAX;
	while (++y < MAP_Y)
	{
		x = UINT64_MAX;
		while (++x < MAP_X)
		{
			if (x + 1 < MAP_X)
				draw_line(graph->screen_srf, (t_d_line){
					(t_pnt){map.dot[y][x].coord.x,
					map.dot[y][x].coord.y},
					(t_pnt){map.dot[y][x + 1].coord.x,
					map.dot[y][x + 1].coord.y}, 0x4286f4});
			if (y + 1 < MAP_Y)
				draw_line(graph->screen_srf, (t_d_line){
					(t_pnt){map.dot[y][x].coord.x,
					map.dot[y][x].coord.y},
					(t_pnt){map.dot[y + 1][x].coord.x,
					map.dot[y + 1][x].coord.y}, 0x4286f4});
		}
	}
}
