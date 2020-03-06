/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <dshpack@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:57:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/04/10 18:57:00 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl_editor.h"

void	init_map(t_map *map)
{
	size_t		y;
	size_t		x;

	y = UINT64_MAX;
	while (++y < MAP_Y)
	{
		x = UINT64_MAX;
		while (++x < MAP_X)
		{
			map->dot[y][x].pos.x = x;
			map->dot[y][x].pos.y = y;
			map->dot[y][x].coord.x = x * ZOOM + OFFSET_X;
			map->dot[y][x].coord.y = y * ZOOM + OFFSET_Y;
			map->dot[y][x].status = FALSE;
			map->dot[y][x].sect_num = -1;
		}
	}
}

void	copy_sectors(t_sect *src, t_sect *dest, size_t size)
{
	size_t		x;

	x = UINT64_MAX;
	while (++x < size)
	{
		dest[x].figure.first.x = src[x].figure.first.x;
		dest[x].figure.first.y = src[x].figure.first.y;
		dest[x].figure.second.x = src[x].figure.second.x;
		dest[x].figure.second.y = src[x].figure.second.y;
		dest[x].figure.third.x = src[x].figure.third.x;
		dest[x].figure.third.y = src[x].figure.third.y;
		dest[x].figure.fourth.x = src[x].figure.fourth.x;
		dest[x].figure.fourth.y = src[x].figure.fourth.y;
		dest[x].pos_x = src[x].figure.first.x;
		dest[x].pos_y = src[x].figure.first.y;
		dest[x].width = src[x].figure.fourth.x;
		dest[x].height = src[x].figure.fourth.y;
		dest[x].type = src[x].type;
		dest[x].id = src[x].id;
	}
}

void	delete_sector(t_sect *src, int id, t_data *sdata, t_map *map)
{
	size_t		x;
	size_t		y;

	y = CALC_Y(src[id].pos_y) - 1;
	while (++y <= (size_t)CALC_Y(src[id].height))
	{
		x = CALC_X(src[id].pos_x) - 1;
		while (++x <= (size_t)CALC_X(src[id].width))
			if (map->dot[y][x].status && map->dot[y][x].sect_num == id)
			{
				map->dot[y][x].status = FALSE;
				map->dot[y][x].sect_num = -1;
				map->dot[y][x].sect_type = NONE;
			}
	}
	x = UINT64_MAX;
	if (id < (int)(sdata->cout - 1))
		copy_sectors(src + id + 1, src + id, sdata->cout - id - 1);
	while (++x < sdata->cout - 1)
		src[x].id = x;
	src[x].id = -1;
	sdata->cout--;
	y = UINT64_MAX;
	while (++y < (size_t)(sdata->cout))
		fill_up_map_cells(map, src + y);
}

t_sect	*recreate_sector_storage(int new_width, int size, t_sect *sec)
{
	size_t	x;
	t_sect	*new;

	new = (t_sect *)malloc(sizeof(t_sect) * new_width);
	x = UINT64_MAX;
	while (++x < (size_t)new_width)
	{
		new[x].id = -1;
		new[x].obj.is_live = -1;
		new[x].obj.type = FALSE;
	}
	if (sec && size)
	{
		copy_sectors(sec, new, size);
		free(sec);
	}
	return (new);
}
