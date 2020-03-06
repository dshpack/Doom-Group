/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:55:01 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/25 13:55:04 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"

void		aaa(t_system *system, int i)
{
	t_it		items[3];

	system->sectors[i].item = items;
}

void		parse_sec(t_system *sys, t_list *list)
{
	t_list		*elem;
	size_t		len;
	size_t		i;

	i = 0;
	len = 0;
	elem = find_elem(list, "sector");
	if (elem)
	{
		len = content_len(elem, "sector");
		sys->sectors = allocate_sec(len);
		while (elem && i < len)
		{
			sys->sectors[i] = parsing(sys, (char *)elem->content);
			aaa(sys, i);
			elem = elem->next;
			i++;
		}
	}
	sys->num_sectors = (unsigned int)len;
}

t_sector	*allocate_sec(size_t size)
{
	t_sector	*sector;

	if (!(sector = (t_sector *)ft_memalloc(sizeof(t_sector) * size)))
		print_error("Error can't allocate memory region");
	return (sector);
}

t_sector	parsing(t_system *sys, char *sector_data)
{
	t_sector	sector;
	char		**dat_arr;

	ft_bzero(&sector, sizeof(t_sector));
	if (sector_data)
	{
		dat_arr = ft_strsplit(ft_strchr(sector_data, '\t'), '\t');
		if (dat_arr && two_len(dat_arr) == 3)
		{
			sector = parse_height_params(dat_arr[M1(1)]);
			sector.vertex = pars_ver_par(dat_arr[M1(2)], sys,
					&sector.ver_arr_len);
			sector.neighbours = parse_neighbours(dat_arr[M1(3)], &sector);
			sector.npoints = sector.ver_arr_len;
			two_del(&dat_arr);
		}
		else
			print_error("Error, wrong sector param number1");
	}
	return (sector);
}

t_bool		int_error(char **data)
{
	while (*data)
	{
		if (!ft_isint(*data, false) && !ft_strchr(*data, '.'))
			print_error("Error, int overload");
		data++;
	}
	return (false);
}
