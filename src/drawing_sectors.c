/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_sectors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <dshpack@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:19:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/06/17 19:19:00 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

int			is_colisn(t_d_line wall_side_cur, t_d_line wall_side_other)
{
	if (wall_side_cur.beg.x == wall_side_other.beg.x
		&& wall_side_cur.end.x == wall_side_other.end.x
		&& wall_side_cur.beg.y == wall_side_other.beg.y
		&& wall_side_cur.end.y == wall_side_other.end.y)
		return (TRUE);
	return (FALSE);
}

int			cheking_all_collisions(t_d_line wsd, t_sec_rect *f, t_sect s)
{
	if ((s.type != RECTANGLE && ((CLS(wsd, (t_d_line){f->fourth, f->second, 0}))
	|| (CLS(wsd, (t_d_line){f->fourth, f->third, 0})) || (CLS(wsd,
		(t_d_line){f->fourth, f->first, 0})) || (CLS(wsd,
		(t_d_line){f->second, f->fourth, 0})) || (CLS(wsd,
		(t_d_line){f->third, f->fourth, 0})) || (CLS(wsd,
		(t_d_line){f->first, f->fourth, 0})) || (CLS(wsd,
		(t_d_line){f->third, f->first, 0})) || (CLS(wsd,
		(t_d_line){f->third, f->second, 0})) || (CLS(wsd,
		(t_d_line){f->second, f->first, 0})) || (CLS(wsd,
		(t_d_line){f->second, f->third, 0})) || (CLS(wsd,
		(t_d_line){f->first, f->second, 0})) || (CLS(wsd,
		(t_d_line){f->first, f->third, 0})))) || (s.type == RECTANGLE
		&& ((CLS(wsd, (t_d_line){f->fourth, f->second, 0})) || (CLS(wsd,
		(t_d_line){f->fourth, f->third, 0})) || (CLS(wsd, (t_d_line){f->fourth,
		f->first, 0})) || (CLS(wsd, (t_d_line){f->third, f->first, 0}))
		|| (CLS(wsd, (t_d_line){f->third, f->second, 0})) || (CLS(wsd,
		(t_d_line){f->second, f->first, 0})) || (CLS(wsd, (t_d_line){f->second,
		f->third, 0})) || (CLS(wsd, (t_d_line){f->second, f->fourth, 0}))
		|| (CLS(wsd, (t_d_line){f->first, f->second, 0})) || (CLS(wsd,
		(t_d_line){f->first, f->third, 0})) || (CLS(wsd, (t_d_line){f->first,
		f->fourth, 0})) || CLS(wsd, (t_d_line){f->third, f->fourth, 0}))))
		return (TRUE);
	return (FALSE);
}

int			is_portal_this_wall(int n, t_d_line wall_sd, t_sect *s)
{
	t_sec_rect	*f;
	size_t		i;

	i = UINT64_MAX;
	while (s[++i].id > -1 && (f = &s[i].figure))
	{
		if (wall_sd.color == 0xD2691E)
			return (FALSE);
		if (i != (size_t)n)
			return (cheking_all_collisions(wall_sd, f, s[i]));
	}
	return (FALSE);
}

void		bolder_line(t_d_line wall, char direction, SDL_Surface *scr,
															void (*funk)())
{
	t_sec_rect		f;

	f = (t_sec_rect){(t_pnt){wall.beg.x, wall.beg.y},
		(t_pnt){wall.end.x, wall.end.y},
		(t_pnt){0, 0}, (t_pnt){0, 0}};
	if (direction == 't')
		return ((*funk)(scr, f, wall.color));
	f = (t_sec_rect){(t_pnt){wall.beg.x, wall.beg.y},
		(t_pnt){0, 0}, (t_pnt){wall.end.x, wall.end.y},
		(t_pnt){0, 0}};
	if (direction == 'l')
		return ((*funk)(scr, f, wall.color));
	f = (t_sec_rect){(t_pnt){0, 0}, (t_pnt){wall.beg.x, wall.beg.y},
		(t_pnt){0, 0}, (t_pnt){wall.end.x, wall.end.y}};
	if (direction == 'r')
		return ((*funk)(scr, f, wall.color));
	f = (t_sec_rect){(t_pnt){0, 0}, (t_pnt){0, 0},
		(t_pnt){wall.beg.x, wall.beg.y}, (t_pnt){wall.end.x, wall.end.y}};
	if (direction == 'd')
		return ((*funk)(scr, f, wall.color));
}

void		bolder_line2(t_d_line wall, char direction, SDL_Surface *scr,
													void (*funk) ())
{
	t_sec_rect		f;

	f = (t_sec_rect){(t_pnt){wall.beg.x, wall.beg.y},
		(t_pnt){0, 0}, (t_pnt){wall.end.x, wall.end.y},
		(t_pnt){0, 0}};
	if (direction == 'l')
		return ((*funk)(scr, f, wall.color));
	f = (t_sec_rect){(t_pnt){wall.beg.x, wall.beg.y},
			(t_pnt){wall.end.x, wall.end.y},
		(t_pnt){0, 0}, (t_pnt){0, 0}};
	if (direction == 'r')
		return ((*funk)(scr, f, wall.color));
	f = (t_sec_rect){ (t_pnt){0, 0}, (t_pnt){wall.beg.x, wall.beg.y},
		(t_pnt){wall.end.x, wall.end.y}, (t_pnt){0, 0}};
	if (direction == 'd')
		return ((*funk)(scr, f, wall.color));
}
