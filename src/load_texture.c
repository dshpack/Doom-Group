/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 19:22:36 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/29 19:22:38 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stable.h"
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

void			safe_write(int fd, const char *source, long remain)
{
	long	result;

	while (remain > 0)
	{
		result = write(fd, source, remain);
		if (result >= 0)
		{
			remain -= result;
			source += result;
		}
		else if (errno == EAGAIN || errno == EINTR)
			continue ;
		else
			break ;
	}
	if (remain > 0)
		perror("write");
}

void			put_texture_set(int fd, t_texture *txtname, t_texture *normname,
	unsigned int *dlm)
{
	safe_write(fd, (const char*)txtname, sizeof(txtname->tex_ture));
	safe_write(fd, (const char*)normname, sizeof(txtname->tex_ture));
	safe_write(fd, (const char*)dlm, sizeof(txtname->tex_ture));
	safe_write(fd, (const char*)dlm, sizeof(txtname->tex_ture));
}

void			loops_for_put_texture_set(t_system *sys,
	t_texture *texture[8], t_ab ab, unsigned int dl[64][64])
{
	size_t w;

	put_texture_set(ab.a, texture[4], texture[5], *dl);
	put_texture_set(ab.a, texture[6], texture[7], *dl);
	w = -1;
	while (++w < sys->sectors[ab.b].npoints)
		put_texture_set(ab.a, texture[0], texture[1], *dl);
	w = -1;
	while (++w < sys->sectors[ab.b].npoints)
		put_texture_set(ab.a, texture[2], texture[3], *dl);
}

void			load_texture2(t_system *sys, int fd)
{
	off_t		filesize;
	char		*td;
	off_t		pos;
	size_t		k;
	unsigned	w;

	filesize = lseek(fd, 0, SEEK_END);
	if (!(td = mmap(NULL, filesize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)))
		ft_putendl("mmap");
	pos = 0;
	k = -1;
	while (++k < sys->num_sectors)
	{
		sys->sectors[k].floortexture = (void*)(td + pos);
		pos += sizeof(t_textureset);
		sys->sectors[k].ceiltexture = (void*)(td + pos);
		pos += sizeof(t_textureset);
		w = sys->sectors[k].npoints;
		sys->sectors[k].uppertextures = (void*)(td + pos);
		pos += sizeof(t_textureset) * w;
		sys->sectors[k].lowertextures = (void*)(td + pos);
		pos += sizeof(t_textureset) * w;
	}
	if (pos != filesize)
		ft_putendl(" -- Wrong filesize! Let's try that again.\n");
}

int				load_texture(t_system *sys)
{
	int				initialized;
	int				fd;
	t_texture		*texture[8];
	unsigned int	dummylightmap[64][64];
	size_t			n;

	fd = open("textures.bin", O_RDWR | O_CREAT, 0644);
	initialized = 0;
	if (lseek(fd, 0, SEEK_END) == 0)
	{
		ft_memset(&dummylightmap, 0, sizeof(dummylightmap));
		create_tex(texture);
		lseek(fd, 0, SEEK_SET);
		n = -1;
		while (++n < sys->num_sectors)
			loops_for_put_texture_set(sys, texture,
				(t_ab) {fd, n}, dummylightmap);
		unload_tex(texture);
		initialized = 1;
	}
	load_texture2(sys, fd);
	if (remove("textures.bin") == -1)
		ft_putendl("Remove Error");
	return (initialized);
}
