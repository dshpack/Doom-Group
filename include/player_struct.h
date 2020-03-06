/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 06:33:37 by olaktion          #+#    #+#             */
/*   Updated: 2019/07/01 06:33:38 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_STRUCT_H
# define PLAYER_STRUCT_H

# include "player_stable.h"
# include "defines.h"
# include "window.h"

typedef struct		s_texture
{
	unsigned int	texture[64][64];
	unsigned int	tex_ture[64][64];
}					t_texture;

typedef struct		s_textureset
{
	unsigned int	texture[64][64];
	unsigned int	normalmap[64][64];
	unsigned int	lightmap[64][64];
	unsigned int	lightmap_diffuseonly[64][64];
}					t_textureset;

typedef struct		s_int_xyz
{
	int				x;
	int				y;
	int				z;
}					t_int_xyz;

typedef struct		s_scaler
{
	int				result;
	int				bop;
	int				fd;
	int				ca;
	int				cache;
}					t_scaler;

typedef struct		s_vertex
{
	double			*x_arr;
	size_t			x_arr_size;
	float			x;
	float			y;
	float			z;
}					t_vertex;

typedef struct		s_xy
{
	float			x;
	float			y;
}					t_xy;

typedef struct		s_ab
{
	int				a;
	int				b;
}					t_ab;

typedef struct		s_wall
{
	int32_t			is_wall;
	float			start_wall[2];
	float			end_wall[2];
}					t_wall;

typedef struct		s_it
{
	t_xy			position;
	int				item_id;
	int				item_width;
	int				item_heigh;
	float			item_w;
	float			item_floor;
	float			item_ceil;
}					t_it;

typedef struct		s_sector
{
	float			floor;
	float			ceil;
	t_xy			*vertex;
	int32_t			*neighbours;
	t_textureset	*floortexture;
	t_textureset	*ceiltexture;
	t_textureset	*uppertextures;
	t_textureset	*lowertextures;
	t_wall			*transit_array;
	size_t			npoints;
	size_t			sec_index;
	size_t			ver_arr_len;
	size_t			color;
	unsigned		textures[8][64 * 64];
	t_it			*item;
	int				light;
}					t_sector;

typedef struct		s_item_math
{
	int				begin_x_room;
	int				end_x_room;
	int				item_num;
	int				y1;
	int				y2;
	float			dist;
	float			vx1_item;
	float			vy1_item;
	float			vx2_item;
	float			vy2_item;
}					t_item_math;

typedef struct		s_item
{
	int				sectorno;
	int				sx1;
	int				sx2;
}					t_item;

typedef struct		s_drawscreen
{
	t_item			queue[MAX_QUEUE];
	t_item			*head;
	t_item			*tail;
	t_item			now;
	int				x;
	int				ytop[W];
	int				ybottom[W];
	size_t			n;
	t_sector		*sect;
	size_t			s;
	t_xy			v1;
	t_xy			v2;
	float			pcos;
	float			psin;
	float			tz1;
	float			tz2;
	float			tx1;
	float			tx2;
	float			nearz;
	float			farz;
	float			nearside;
	float			farside;
	t_xy			i1;
	t_xy			i2;
	t_xy			scale1;
	t_xy			scale2;
	int				x1;
	int				x2;
	float			yceil;
	float			yfloor;
	t_ab			y1;
	t_ab			y2;
	int				neighbour;
	float			nyceil;
	float			nyfloor;
	t_ab			ny1;
	t_ab			ny2;
	int				beginx;
	int				endx;
	int				xrw;
	t_ab			y;
	int				z;
	t_ab			cy;
	t_ab			ny;
	t_ab			cny;
	int				r1;
	int				r2;
	int				r;
	int				v;
	int				u;
	t_item_math		item;
	int				u0;
	int				u1;
	t_xy			org1;
	t_xy			org2;
	float			hei;
	float			mapx;
	float			mapz;
	float			rtx;
	float			rtz;
	unsigned		txtx;
	unsigned		txtz;
	int				pel;
	t_scaler		nya_int;
	t_scaler		nyb_int;
	int				***card;
	int				**img_buff;
}					t_dscreen;

typedef struct		s_square
{
	float			square;
	float			x;
	float			y;
	float			x0;
	float			y0;
}					t_square;

typedef struct		s_line
{
	float			x0;
	float			y0;
	float			x1;
	float			y1;
	int				x;
	int				y;
	int				color;
	float			opacity;
}					t_line;

typedef struct		s_iline
{
	t_xy			zero;
	t_xy			one;
	int				color;
}					t_iline;

typedef struct		s_xyz
{
	float			x;
	float			y;
	float			z;
}					t_xyz;

typedef struct		s_abc
{
	float			a;
	float			b;
	float			c;
}					t_abc;

typedef struct		s_pos
{
	int				wsad[4];
	int				ground;
	int				falling;
	int				moving;
	int				ducking;
	int				map;
	int				flying;
}					t_pos;

typedef struct		s_inv
{
	int				yellow_key;
	int				red_key;
	int				green_key;
	int				exit_key;
}					t_inv;

typedef struct		s_player
{
	t_xyz			where;
	t_xyz			velocity;
	float			angle;
	float			anglesin;
	float			anglecos;
	float			yaw;
	t_pos			pos;
	int32_t			num_sect;
	int				ammo;
	int				health;
	t_inv			inv;
}					t_player;

typedef struct		s_sprite
{
	int				count;
	t_abc			where;
	int32_t			num_sect;
	int				texture[604][604];
	SDL_Surface		*sprites_surface;
	t_item_math		item;
}					t_sprite;

typedef struct		s_menu_text
{
	SDL_Surface		*font_surf;
	SDL_Texture		*font_textr;
	SDL_Rect		font_rect;
}					t_menu_text;

typedef struct		s_text
{
	int				size;
	t_xy			pos;
	SDL_Color		color;
}					t_text;

typedef struct		s_menu
{
	SDL_Surface		*menu;
	int				menu_nb;
	int				flag;
	char			*str[3];
	t_menu_text		menu_text;
	SDL_Color		menu_color;
	int				menu_status;
}					t_menu;

typedef struct		s_hud
{
	SDL_Surface		*hud_surf;
	SDL_Color		hud_color;
	SDL_Texture		*hud_texture;
	t_menu_text		hud_text;
}					t_hud;

typedef struct		s_dev
{
	int				dev_mode;
	int				time;
	int				flag;
	int				obj;
	int				kills;
	double			a;
	double			b;
	double			c;
	int				r;
	int				sqrt_discr;
}					t_dev;

typedef struct		s_system
{
	t_dev			dev;
	unsigned		num_sectors;
	t_sector		*sectors;
	SDL_Surface		*surface;
	SDL_Window		*window;
	t_player		*player;
	t_dscreen		dscreen;
	t_window		wh;
	t_vertex		*vertex;
	size_t			sum_vert;
	size_t			sum_vert_pair;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	t_menu			menu;
	t_hud			hud;
	char			*map;
	int				map_i;
	SDL_Surface		*fake_surface;
	TTF_Font		*font_ttf;
	int				**surface_box;
	Mix_Music		*music;
	int				tex_tx;
}					t_system;

typedef struct		s_pixel
{
	float			r;
	float			g;
	float			b;
	float			brightness;
}					t_pixel;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

#endif
