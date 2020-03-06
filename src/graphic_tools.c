/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <dshpack@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:53:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/04/11 20:53:00 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void		drl(t_d_line *l, t_f_l *line, SDL_Surface *scr)
{
	line->d.x = l->end.x - l->beg.x >= 0 ? 1 : -1;
	line->d.y = l->end.y - l->beg.y >= 0 ? 1 : -1;
	line->ln.x = abs(l->end.x - l->beg.x);
	line->ln.y = abs(l->end.y - l->beg.y);
	line->ln.ln = fmax(line->ln.x, line->ln.y);
	if (line->ln.ln == 0)
		set_pixel(scr->pixels, (t_pnt){ l->beg.x, l->beg.y }, scr->w, 0x2a2a41);
	line->tmp.x = l->beg.x;
	line->tmp.y = l->beg.y;
}

void		drl_i(SDL_Surface *scr, t_d_line *l, t_f_l *line)
{
	set_pixel(scr->pixels, (t_pnt){line->tmp.x, line->tmp.y}, scr->w, l->color);
	line->tmp.x += line->d.x;
	line->dd += 2 * line->ln.y;
	if (line->dd > 0)
	{
		line->dd -= 2 * line->ln.x;
		line->tmp.y += line->d.y;
	}
}

void		drl_e(SDL_Surface *scr, t_d_line *l, t_f_l *line)
{
	set_pixel(scr->pixels, (t_pnt){line->tmp.x, line->tmp.y}, scr->w, l->color);
	line->tmp.y += line->d.y;
	line->dd += 2 * line->ln.x;
	if (line->dd > 0)
	{
		line->dd -= 2 * line->ln.y;
		line->tmp.x += line->d.x;
	}
}

void		draw_line(SDL_Surface *scr, t_d_line l)
{
	t_f_l		line;

	drl(&l, &line, scr);
	line.ln.ln++;
	if (line.ln.y <= line.ln.x)
	{
		line.dd = -line.ln.x;
		while (line.ln.ln--)
			drl_i(scr, &l, &line);
	}
	else
	{
		line.dd = -line.ln.y;
		while (line.ln.ln--)
			drl_e(scr, &l, &line);
	}
}
