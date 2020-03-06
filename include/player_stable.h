/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_stable.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <osak@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 05:55:37 by osak              #+#    #+#             */
/*   Updated: 2019/07/01 05:55:40 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_STABLE_H
# define PLAYER_STABLE_H

# include <math.h>
# include <SDL_image.h>
# include <SDL_ttf.h>
# include <SDL_mixer.h>
# include <SDL.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <unistd.h>
# include "get_next_line.h"
# include "player_struct.h"
# include "defines.h"
# include "window.h"
# include "lvl_editor.h"

void			draw_text(t_system *sys, char *text, t_text txt);
void			draw_lines(t_system *sys);
t_text			set_txt(int x, int y, SDL_Color color, int font_size);
SDL_Surface		*load_image(char *path);
void			load_music(t_system *system);
void			draw_sprites_in_sector(t_system *system);

void			load_things(t_system *sys);
void			render_things(t_system *sys, SDL_Texture *game_texture);
void			mouse_event(t_player *player, t_system *sys, float *yaw);

void			mvs1(int s, t_sector *sector, float const *eyeh, t_system *sys);
void			mvs(t_player *player, t_system *sys, float const *eyeh, int s);
void			falling(t_player *player, t_system *sys, float const eyeheight);

void			event_init(t_system *system, t_player *player, SDL_Event ev);
int				key_event(t_system *system);
void			result(float *move_vec, t_player *player);
void			move(t_player *player);

void			init_main_cycle(t_player *player, t_system *sys,
				SDL_Texture *game_texture);
void			draw_screen(t_system *sys);
void			main_cycle_sdl(t_system *sys, SDL_Texture *game_texture);
void			main_cycle(t_player *player, t_system *sys, float yaw);

int				event_menu(t_system *sys, t_player *player);
int				event_menu2(t_system *sys, t_player *plyer, SDL_Event ev);
int				start_menu(void);
void			menu_text(t_system *sys);
void			hud_text(t_system *sys);

void			move_player(t_player *player, t_sector *sectors, t_xy d);
void			pos_m(t_system *sys, t_player *player, float *eyeheight);
t_xyz			define_position(char *data);

void			free_main_cycle(SDL_Texture *game_texture, t_system *system);
void			unload_tex(t_texture **tex);
int				done(t_system *system);
void			draw_screen(t_system *sys);

void			init_player(t_player *player);
void			init_window(t_system *sys);
t_system		*init_system(void);

void			for_neighbour(t_system *sys);
void			cycle_xrw_endx(t_system *sys);
void			include_in_drawscreen(t_system *sys);

void			check_the_edge_type(t_system *sys);
void			acquire_coords(t_system *sys);
void			vline2(t_int_xyz xyz, t_scaler ty, const t_textureset *t,
		t_system *sys);

void			draw_screen(t_system *sys);
t_scaler		scaler_init(t_int_xyz abc, int d, int f);
t_xy			intersect_def(t_xy one, t_xy two, t_xy three, t_xy four);
int				intersect_box(t_xy zero, t_xy one, t_xy two, t_xy three);
int				point_side(t_xy p, t_xy zero, t_xy one);

void			create_tex(t_texture **texture);
void			load_textures(char *string, t_texture *tex);
int				load_items(t_system *system);

void			safe_write(int fd, const char *source, long remain);
void			put_texture_set(int fd, t_texture *txtname, t_texture *normname,
								unsigned int *dlm);
void			loops_for_put_texture_set(t_system *sys, t_texture *texture[8],
		t_ab ab, unsigned int dl[64][64]);
void			load_texture2(t_system *sys, int fd);
int				load_texture(t_system *sys);

void			skybox_vline(t_system *sys, int x, int start_x);
void			draw_skybox(t_system *sys);
void			load_surface_skybox(t_system *sys, SDL_Surface *sky_box);
int				load_skybox(t_system *sys);

void			transform_vertices(t_system *sys);
void			yaw_calc(t_system *system);
void			transform_floor_ceiling(t_system *sys);
int				scaler_next(t_scaler *i);
void			scales(t_system *sys);

void			view_frustrum_help(t_system *sys);
void			view_frustrum_next(t_system *sys);
void			draw_screen_init(t_system *sys, int *renderedsectors);
void			before_view_frustrum(t_system *sys);
void			after_view_frustrum(t_system *sys);

void			before_cycle_helper(t_system *system);
void			for_cycle_helper(t_system *system, int y);
void			for_cycle(t_system *system);

void			view_frustrum_next(t_system *sys);
void			draw_screen_init(t_system *sys, int *renderedsectors);
void			scales(t_system *sys);

int				go(t_system *sys, t_player *player);
int				event_help(t_system *sys, SDL_Event ev, t_player *player);
int				main(int argc, char **argv);

t_system		*init_system(void);

void			read_file(t_system *sys);
void			parse_all(t_system *sys, t_list *list);
void			print_error(const char *msg);
void			tmp_list(t_list **lst, const void *content,
	const size_t content_size);
void			free_tmp_list(t_list **head);

void			parse_vertex(t_system *sys, t_list *list);
t_list			*find_elem(t_list *list, char *elem);
size_t			content_len(t_list *list, char *content);
t_vertex		*allocate_vertex(size_t size);
t_xy			*pars_ver_par(char *data, t_system *sys, size_t *len);

t_bool			validate_vertex(char *vertex_data);
t_bool			validate_dilims(char *vertex_data);
t_bool			validate_coords(char *vertex_data);
t_bool			validate_num(char *vertex_data);
double			*allocate_vertex_x_array(size_t size);

float			parse_ver_y(char *vertex_line);
double			*parse_ver_x(char *vertex_line, size_t *size_arr);
char			*find_x_values(char *vertex_line);
size_t			two_len(char **array);
void			two_del(char ***array);

void			parse_sec(t_system *sys, t_list *list);
t_sector		*allocate_sec(size_t size);
t_sector		parsing(t_system *sys, char *sector_data);
t_bool			int_error(char **data);

t_sector		parse_height_params(char *data);
t_xy			*parse_vertex_pair(t_system *sys, char **data, size_t size);
t_xy			*search_vertex_pair(t_system *sys, int32_t pair);
double			*allocate_vertex_pair();

void			parse_player(t_system *sys, t_list *list);
t_player		parse_player_parameters(char *data);
int32_t			*parse_neighbours(char *data, t_sector *sector);

void			sprite_casting(t_system *system);
void			perspective_transformation(t_system *sys);
int				calc_sprite_view(t_system *sys);
void			find_sprite_visual(t_system *sys, float dist);
void			draw_key_sprite(t_system *sys, int key);
void			vline_card(t_system *sys, int x, int tex_num);
void			set_color(t_system *sys, int x, int y, int tex_num);
float			interpolate(t_system *sys, float cmprsd_txtr,
		float sampling_ratio);

void			parse_player_helper(t_player *player, char **tmp);
void			pn_helper(t_sector *sector, size_t idx, size_t i,
		int32_t *neighbours);

#endif
