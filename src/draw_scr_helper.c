/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scr_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 14:24:31 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/30 14:24:32 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

int				overlap(t_xy a, t_xy b)
{
	return ((MIN(a.x, a.y) <= MAX(b.x, b.y) && MIN(b.x, b.y) <= MAX(a.x, a.y)));
}

int				point_side(t_xy p, t_xy zero, t_xy one)
{
	return (SIGN(VXS((one.x) - (zero.x), (one.y) - (zero.y),
		(p.x) - (zero.x), (p.y) - (zero.y))));
}

int				intersect_box(t_xy zero, t_xy one, t_xy two, t_xy three)
{
	return (overlap((t_xy) {zero.x, one.x}, (t_xy) {two.x, three.x})
		&& overlap((t_xy) {zero.y, one.y}, (t_xy) {two.y, three.y}));
}

t_scaler		scaler_init(t_int_xyz abc, int d, int f)
{
	t_scaler	scaler;

	scaler.result = d + (abc.y - 1 - abc.x) * (f - d) / (abc.z - abc.x);
	scaler.bop = ((f < d) ^ (abc.z < abc.x)) ? -1 : 1;
	scaler.fd = ABS(f - d);
	scaler.ca = ABS(abc.z - abc.x);
	scaler.cache = (int)((abc.y - 1 - abc.x) * ABS(f - d)) % ABS(abc.z - abc.x);
	return (scaler);
}

t_xy			intersect_def(t_xy one, t_xy two, t_xy three, t_xy four)
{
	t_xy	res;

	res.x = VXS(VXS(one.x, one.y, two.x, two.y), (one.x) - (two.x),
		VXS(three.x, three.y, four.x, four.y), (three.x) - (four.x))
	/ VXS((one.x) - (two.x), (one.y) - (two.y), (three.x) - (four.x),
		(three.y) - (four.y));
	res.y = VXS(VXS(one.x, one.y, two.x, two.y), (one.y) - (two.y),
		VXS(three.x, three.y, four.x, four.y), (three.y) - (four.y))
	/ VXS((one.x) - (two.x), (one.y) - (two.y), (three.x) - (four.x),
		(three.y) - (four.y));
	return (res);
}
