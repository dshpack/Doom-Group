/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_visualizer4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <dshpack@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:45:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/05/22 18:45:00 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void		draw_rect(SDL_Surface *srf, t_sec_rect f, Uint32 color)
{
	t_pnt		beg;
	t_pnt		end;
	int			x;

	x = -1;
	while (++x < 3)
	{
		beg = (t_pnt){ f.first.x, f.first.y + x };
		end = (t_pnt){ f.second.x, f.second.y + x };
		if (f.first.x && f.first.y - x && f.second.x && f.second.y - x)
			draw_line(srf, (t_d_line){ beg, end, color });
		beg = (t_pnt){ f.first.x + x, f.first.y };
		end = (t_pnt){ f.third.x + x, f.third.y };
		if (f.first.x - x && f.first.y && f.third.x - x && f.third.y)
			draw_line(srf, (t_d_line){ beg, end, color });
		beg = (t_pnt){ f.second.x - x, f.second.y };
		end = (t_pnt){ f.fourth.x - x, f.fourth.y };
		if (f.second.x + x && f.second.y && f.fourth.x + x && f.fourth.y)
			draw_line(srf, (t_d_line){ beg, end, color });
		beg = (t_pnt){ f.third.x, f.third.y - x };
		end = (t_pnt){ f.fourth.x, f.fourth.y - x };
		if (f.third.x && f.third.y + x && f.fourth.x && f.fourth.y + x)
			draw_line(srf, (t_d_line){ beg, end, color });
	}
}

void		draw_triangle_down_r(SDL_Surface *srf, t_sec_rect f, Uint32 color)
{
	t_pnt		beg;
	t_pnt		end;
	int			x;

	x = -1;
	while (++x <= 3)
	{
		beg = (t_pnt){ f.first.x, f.first.y + x };
		end = (t_pnt){ f.third.x + x, f.third.y };
		if (f.first.x && f.first.y && f.third.x && f.third.y)
			draw_line(srf, (t_d_line){ beg, end, color });
		beg = (t_pnt){ f.first.x - x, f.first.y + x };
		end = (t_pnt){ f.second.x - x, f.second.y };
		if (f.first.x && f.first.y && f.second.x && f.second.y)
			draw_line(srf, (t_d_line){ beg, end, color });
		beg = (t_pnt){ f.third.x + x, f.third.y - x };
		end = (t_pnt){ f.second.x, f.second.y - x };
		if (f.second.x && f.second.y && f.third.x && f.third.y)
			draw_line(srf, (t_d_line){ beg, end, color });
	}
}

void		draw_triangle_down_l(SDL_Surface *srf, t_sec_rect f, Uint32 color)
{
	t_pnt		beg;
	t_pnt		end;
	int			x;

	x = -1;
	while (++x <= 3)
	{
		beg = (t_pnt){ f.first.x, f.first.y + x };
		end = (t_pnt){ f.third.x - x, f.third.y };
		if (f.first.x && f.first.y && f.third.x && f.third.y)
			draw_line(srf, (t_d_line){ beg, end, color });
		beg = (t_pnt){ f.first.x + x, f.first.y + x };
		end = (t_pnt){ f.second.x + x, f.second.y };
		if (f.first.x && f.first.y && f.second.x && f.second.y)
			draw_line(srf, (t_d_line){ beg, end, color });
		beg = (t_pnt){ f.third.x - x, f.third.y - x };
		end = (t_pnt){ f.second.x + x, f.second.y - x };
		if (f.second.x && f.second.y && f.third.x && f.third.y)
			draw_line(srf, (t_d_line){ beg, end, color });
	}
}

void		draw_triangle_right(SDL_Surface *srf, t_sec_rect f, Uint32 color)
{
	t_pnt		beg;
	t_pnt		end;
	int			x;

	x = -1;
	while (++x <= 3)
	{
		beg = (t_pnt){ f.first.x + x, f.first.y };
		end = (t_pnt){ f.third.x, f.third.y - x };
		if (f.first.x && f.first.y && f.third.x && f.third.y)
			draw_line(srf, (t_d_line){beg, end, color});
		beg = (t_pnt){ f.first.x + x, f.first.y + x };
		end = (t_pnt){ f.second.x, f.second.y + x };
		if (f.first.x && f.first.y && f.second.x && f.second.y)
			draw_line(srf, (t_d_line){beg, end, color});
		beg = (t_pnt){ f.second.x - x, f.second.y + x };
		end = (t_pnt){ f.third.x - x, f.third.y - x };
		if (f.second.x && f.second.y && f.third.x && f.third.y)
			draw_line(srf, (t_d_line){beg, end, color});
	}
}

void		draw_triangle_left(SDL_Surface *srf, t_sec_rect f, Uint32 color)
{
	t_pnt		beg;
	t_pnt		end;
	int			x;

	x = -1;
	while (++x <= 3)
	{
		beg = (t_pnt){ f.first.x + x, f.first.y};
		end = (t_pnt){ f.third.x + x, f.third.y - x };
		if (f.first.x && f.first.y && f.third.x && f.third.y)
			draw_line(srf, (t_d_line){beg, end, color});
		beg = (t_pnt){ f.second.x - x, f.second.y };
		end = (t_pnt){ f.third.x, f.third.y - x };
		if (f.second.x && f.second.y && f.third.x && f.third.y)
			draw_line(srf, (t_d_line){ beg, end, color });
		beg = (t_pnt){ f.first.x, f.first.y + x };
		end = (t_pnt){ f.second.x - x, f.second.y + x };
		if (f.first.x && f.first.y && f.second.x && f.second.y)
			draw_line(srf, (t_d_line){ beg, end, color });
	}
}
