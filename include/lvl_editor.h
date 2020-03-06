/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl_editor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <dshpack@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:24:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/12/01 18:24:00 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LVL_EDITOR_H
# define LVL_EDITOR_H
# define WIN_WIDTH 2360
# define WIN_HEIGHT 1200
# define OFFSET_X 455
# define OFFSET_Y 25
# define ZOOM 25
# define MAP_X 76
# define MAP_Y 46
# define WIREFRAME_W 2330
# define WIREFRAME_H 1350
# define TRUE (1)
# define FALSE (0)
# define CALC_X(x) ((x - OFFSET_X) / ZOOM)
# define CALC_Y(y) ((y - OFFSET_Y) / ZOOM)
# define SF s->figure
# define FS figure->second
# define FF figure->first
# define FT figure->third
# define FFO figure->fourth
# define ENVS env->sdata
# define RF rect.first
# define RS rect.second
# define RT rect.third
# define CLS is_colisn
# define S_NUM(y, x) (map.dot[y][x].sect_num)
# define S_TYPE(y, x) (map.dot[y][x].sect_type)
# define DOT(y, x) (map.dot[y][x])
# define SEC(x) (data.sec[x])
# define COLOR1 0x101413
# define COLOR2 0x212121
# define TMPOBJ tmp_obj->coord
# define FMP flags->mouse_pos

# include "player_stable.h"

enum				e_arrows
{
	NOT_ACTIVE_L = 0,
	NOT_ACTIVE_R = 1,
	ACTIVE_L = 2,
	ACTIVE_R = 3
};

enum				e_sectors_objects
{
	NO_OBJ = -1,
	TRUE_PL = 31,
	TRUE_ENEMY = 32,
	TRUE_START = 33,
	TRUE_STAIRWAY = 34,
	TRUE_FINISH = 35,
	TRUE_HELTH = 36,
	TRUE_ARM_SHELL = 37,
	TRUE_BODY_ARMOR = 38,
	TRUE_HELMET = 39,
	TRUE_GUN = 40,
	TRUE_MACHINE_GUN = 41,
	TRUE_BULLETS = 42,
	TRUE_MAGAZINE = 43,
	FALSE_PL = 18,
	FALSE_ENEMY = 19,
	FALSE_START = 20,
	FALSE_STAIRWAY = 21,
	FALSE_FINISH = 22,
	FALSE_HELTH = 23,
	FALSE_ARM_SHELL = 24,
	FALSE_BODY_ARMOR = 25,
	FALSE_HELMET = 26,
	FALSE_GUN = 27,
	FALSE_MACHINE_GUN = 28,
	FALSE_BULLETS = 29,
	FALSE_MAGAZINE = 30,
};

enum				e_sectors_types
{
	NONE = -1,
	RECTANGLE = 9,
	TRIANGLE_DOWN_R = 11,
	TRIANGLE_DOWN_L = 13,
	TRIANGLE_UP_R = 14,
	TRIANGLE_UP_L = 17
};

typedef struct		s_graphics
{
	SDL_Window		*window;
	SDL_Surface		*screen_srf;
	SDL_Surface		*screen;
	SDL_Surface		*menu_cont;
	SDL_Texture		*texture;
	SDL_Renderer	*renderer;
	TTF_Font		*fonts;
	SDL_Surface		*mouse_text;
	SDL_Rect		btn_start[2];
	SDL_Rect		clip[6];
	SDL_Rect		menu[44];
	SDL_Rect		obj[14];
	SDL_Rect		textures[30];
	SDL_Surface		*arrow_left;
	SDL_Surface		*arrow_right;
	SDL_Surface		*walls[10];
	SDL_Surface		*sector_shape[4];
	SDL_Surface		*sprites[5];
}					t_graph;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_pnt;

typedef struct		s_sector_object
{
	t_pnt			coord;
	t_pnt			pos;
	int				type;
	int				is_live;
}					t_inner;

typedef struct		s_sector_frame
{
	t_pnt			coord;
	t_pnt			pos;
	int				w;
	int				h;
}					t_outer;

typedef struct		s_wireframe_dots
{
	t_pnt			pos;
	t_pnt			coord;
	int				status;
	int				sect_num;
	int				sect_type;
}					t_dots;

typedef struct		s_map
{
	t_dots			dot[MAP_Y][MAP_X];
	int				wall_nb;
	int				sector_shape;
	int				sector_size;
	int				sprite_nb;
}					t_map;

typedef struct		s_pixel_param
{
	t_pnt			coords;
	int				*buffer;
	int				width;
	Uint32			color;
}					t_px;

typedef struct		s_circle
{
	t_pnt			pt;
	t_pnt			cntr;
	Uint32			col;
	int				pos;
	int				radius;
}					t_circle;

typedef struct		s_sector_wall
{
	t_pnt			beg;
	t_pnt			end;
}					t_s_wall;

typedef struct		s_sector_walls_arr
{
	t_pnt			beg;
	t_pnt			end;
	int				num;
}					t_warr;

typedef struct		s_sector_dots
{
	t_pnt			mouse;
	t_pnt			max;
}					t_sec_d;

typedef struct		s_sector_rectangle
{
	t_pnt			first;
	t_pnt			second;
	t_pnt			third;
	t_pnt			fourth;
}					t_sec_rect;

typedef struct		s_sector_for_editor
{
	t_sec_rect		figure;
	t_inner			obj;
	int				floor;
	int				ceiling;
	int				frame_cout;
	int				obj_pos_cout;
	int				obj_cout;
	int				pos_x;
	int				pos_y;
	int				width;
	int				height;
	int				type;
	int				id;
}					t_sect;

typedef struct		s_sectors_data
{
	t_sect			*sec;
	t_sect			*tmp_sec;
	t_inner			*tmp_obj;
	unsigned int	cout;
	int				store_size;
	int				tmp_type;
	int				tmp_w;
	int				tmp_h;
}					t_data;

typedef struct		s_length
{
	int				x;
	int				y;
	int				ln;
}					t_len;

typedef struct		s_fot_line
{
	t_pnt			d;
	int				dd;
	t_pnt			tmp;
	t_len			ln;
}					t_f_l;

typedef struct		s_params_to_render
{
	SDL_Surface		*scr;
	Uint32			color;
}					t_render;

typedef struct		s_bresenham
{
	t_pnt			beg;
	t_pnt			end;
	Uint32			color;
}					t_d_line;

typedef struct		s_text_to_render
{
	char			*line;
	SDL_Color		color;
	t_pnt			pos;
	int				size;
}					t_ttf_p;

typedef struct		s_menu_elements
{
	int				type_btn;
	int				active;
	int				object_btn;
	int				create_sec;
	int				create_obj;
}					t_elem;

typedef struct		s_arrows_status
{
	int				w_l;
	int				w_r;
	int				h_l;
	int				h_r;
}					t_arrows;

typedef struct		s_active_player
{
	t_pnt			coords;
	int				status;
	int				err_msg;
}					t_pl;

typedef struct		s_event_flags
{
	t_arrows		arrow;
	t_elem			sec;
	t_pnt			mouse_pos;
	t_pnt			curr_pos;
	int				on_pos;
	int				running;
	int				arrow_press;
	int				btn_delete;
	int				l_mouse_down;
	int				btn_space;
	int				btn_up;
	int				btn_down;
	int				btn_left;
	int				btn_right;
	t_pl			player;
	int				game_start;
}					t_eflags;

typedef struct		s_environment
{
	t_graph			*graph;
	t_eflags		*flags;
	t_data			sdata;
	t_map			map;
}					t_env;

typedef struct		s_global_data
{
	t_warr			walls[45];
	int				wall_cout;
	int				num_sectors;
	t_sector		sectors[45];
	int				sec_cout;
	t_player		pl;
	t_sprite		sprite[45];
	int				sprite_cout;
}					t_global;

void				prepare_menu_cont(t_graph *g);
void				apply_surface(t_graph *graph);
void				event_handler(t_eflags *flags, t_elem *sec, t_env *env);
void				searching_nearest_point(t_eflags *flags,
								t_env *env, int flag);
void				init_sector(t_pnt mouse, t_sect *s, t_env *env);
void				event_arrows_handler_parameters(t_data *d, t_eflags *flags);
void				event_listener(t_eflags *flags, t_env *env);
void				draw_line(SDL_Surface *scr, t_d_line l);
char				*write_text(t_ttf_p text, t_graph *graph);
void				set_pixel(int *buffer, t_pnt coords,
							int width, Uint32 color);
void				bolder_line(t_d_line wall, char direction,
							SDL_Surface *scr, void (*funk) ());
void				draw_rect(SDL_Surface *srf, t_sec_rect f, Uint32 color);
void				draw_triangle_down_r(SDL_Surface *srf,
								t_sec_rect f, Uint32 color);
void				draw_triangle_down_l(SDL_Surface *srf,
								t_sec_rect f, Uint32 color);
void				draw_triangle_right(SDL_Surface *srf,
								t_sec_rect f, Uint32 color);
void				draw_triangle_left(SDL_Surface *srf,
								t_sec_rect f, Uint32 color);
void				draw_menu_main(t_env *env);
void				draw_sector_menu(t_env *env, t_graph *g, t_eflags *f);
void				surf_to_scr(t_xy xy, t_graph *graph, SDL_Rect *clip,
								SDL_Surface *icon);
void				draw_map(t_map map, t_graph *graph);
void				draw_context(t_graph *g, t_eflags *f);
void				draw_created_sectors(t_env *env);
void				clear_surface_scr(SDL_Surface *screen);
void				apply_surface(t_graph *graph);
int					init(t_graph *graph);
int					load_content(t_graph *graph);
SDL_Surface			*load_editor_image(const char *filename);
void				log_sdl_error(const char *msg);
void				close_program(t_graph *graph);
void				init_map(t_map *map);
void				fill_up_map_cells(t_map *map, t_sect *s);
void				copy_sectors(t_sect *src, t_sect *dest, size_t size);
t_sect				*recreate_sector_storage(int new_width,
								int size, t_sect *sec);
int					is_place_occupied(t_sect *s, t_map map);
void				delete_sector(t_sect *src, int id,
							t_data *sdata, t_map *map);
void				sectors_worker(t_eflags *flags, t_elem *sec,
								t_env *env, t_sect **tmp);
void				show_error_message(int key, t_env *env);
int					is_portal_this_wall(int n, t_d_line wall_sd, t_sect *s);
void				menu_initer_main(t_graph *g);
int					start_lvl_editor(void);
void				try_draw_sector(t_sect *s, t_graph *graph, t_env *env);
void				main_menu(t_env *env, t_graph *g,
						SDL_Rect *menu, t_eflags *f);
void				init_menu_rect_fourth(t_graph *g);
void				init_menu_rect_third(t_graph *g);
void				init_menu_rect_second(t_graph *g);
void				init_menu_rect(t_graph *g);
void				fill_up_by_trgnl_d_l(t_map *map, t_sect *s);
void				fill_up_by_trgnl_d_r(t_map *map, t_sect *s);
void				map_dot(t_map *map, t_sect *s, int x, int y);
t_sec_rect			init_triangle_dots(t_pnt mouse, t_sect *s, t_env *env);
void				init_variables(t_env *env);
void				restore_params(t_eflags *flags);
void				init_main_variables(t_env **env);
void				bolder_line2(t_d_line wall,
					char direction, SDL_Surface *scr,
						void (*funk) ());
void				check_mouse_pos(int x, int y, int *on_pos);
void				find_choosen_sector_type(int x, int y,
					int *type, int *sec_active);
void				find_ch_o(int x, int y, int *type);
void				find_choosen_object(int x, int y, int *type);
void				keyboard_event(SDL_Event event, SDL_Keycode key,
					t_eflags *flags);

#endif
