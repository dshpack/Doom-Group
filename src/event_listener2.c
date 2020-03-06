/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <osak@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 05:40:47 by osak              #+#    #+#             */
/*   Updated: 2019/07/01 05:40:48 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void			check_mouse_pos(int x, int y, int *on_pos)
{
	if (x >= 20 && y >= 65 && x < 90 && y <= 135)
		*on_pos = RECTANGLE;
	else if (x >= 90 && y >= 65 && x < 160 && y <= 135)
		*on_pos = TRIANGLE_DOWN_R;
	else if (x >= 170 && y >= 65 && x < 240 && y <= 135)
		*on_pos = TRIANGLE_DOWN_L;
	else if (x >= 240 && y >= 65 && x < 310 && y <= 135)
		*on_pos = TRIANGLE_UP_R;
	else if (x >= 310 && y >= 65 && x < 380 && y <= 135)
		*on_pos = TRIANGLE_UP_L;
	else
		*on_pos = NONE;
}

void			find_choosen_sector_type(int x, int y, int *type,
	int *sec_active)
{
	*sec_active = -1;
	if (x >= 20 && y >= 65 && x < 90 && y <= 135 && *type != RECTANGLE)
		*type = RECTANGLE;
	else if (x >= 90 && y >= 65 && x < 160 && y <= 135
	&& *type != TRIANGLE_DOWN_R)
		*type = TRIANGLE_DOWN_R;
	else if (x >= 170 && y >= 65 && x < 240 && y <= 135
	&& *type != TRIANGLE_DOWN_L)
		*type = TRIANGLE_DOWN_L;
	else if (x >= 240 && y >= 65 && x < 310 && y <= 135
	&& *type != TRIANGLE_UP_R)
		*type = TRIANGLE_UP_R;
	else if (x >= 310 && y >= 65 && x < 380 && y <= 135
	&& *type != TRIANGLE_UP_L)
		*type = TRIANGLE_UP_L;
	else
		*type = NONE;
}

void			find_ch_o(int x, int y, int *type)
{
	if (x >= 115 && y >= 600 && x <= 185 && y <= 670)
		*type = TRUE_ARM_SHELL;
	else if (x >= 215 && y >= 600 && x <= 285 && y <= 670)
		*type = TRUE_BODY_ARMOR;
	else if (x >= 300 && y >= 600 && x <= 370 && y <= 670)
		*type = TRUE_HELMET;
	else if (x >= 30 && y >= 720 && x <= 100 && y <= 790)
		*type = TRUE_GUN;
	else if (x >= 115 && y >= 720 && x <= 185 && y <= 790)
		*type = TRUE_MACHINE_GUN;
	else if (x >= 215 && y >= 720 && x <= 285 && y <= 790)
		*type = TRUE_BULLETS;
	else if (x >= 300 && y >= 720 && x <= 370 && y <= 790)
		*type = TRUE_MAGAZINE;
	else
		*type = NO_OBJ;
}

void			find_choosen_object(int x, int y, int *type)
{
	if (x >= 120 && y >= 360 && x <= 190 && y <= 430)
		*type = TRUE_PL;
	else if (x >= 210 && y >= 360 && x <= 280 && y <= 430)
		*type = TRUE_ENEMY;
	else if (x >= 85 && y >= 475 && x <= 155 && y <= 545)
		*type = TRUE_START;
	else if (x >= 165 && y >= 475 && x <= 235 && y <= 545)
		*type = TRUE_STAIRWAY;
	else if (x >= 245 && y >= 475 && x <= 315 && y <= 545)
		*type = TRUE_FINISH;
	else if (x >= 30 && y >= 600 && x <= 100 && y <= 670)
		*type = TRUE_HELTH;
	else
		find_ch_o(x, y, type);
}

void			keyboard_event(SDL_Event event, SDL_Keycode key,
	t_eflags *flags)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (key == SDLK_ESCAPE)
		{
			flags->sec.active = -1;
			flags->sec.type_btn = NONE;
			flags->sec.create_sec = FALSE;
			flags->sec.object_btn = NO_OBJ;
		}
		if (key == SDLK_DELETE && flags->sec.active > -1)
			flags->btn_delete = 1;
	}
}
