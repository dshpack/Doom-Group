/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 22:52:32 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/30 22:52:33 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_NUKEM_DEFINES_H
# define DOOM_NUKEM_DEFINES_H

# define EYEHEIGHT  6
# define DUCKHEIGHT 2.5
# define HEADMARGIN 1
# define KNEEHEIGHT 2

# define YELLOW_KEY 0
# define RED_KEY 1
# define GREEN_KEY 2

# define SPR_H	64
# define SPR_W	64

# define HFOV (1.0 * 0.73f*H/W)
# define VFOV (1.0 * .2f)
# define YAW(y,z) (y + z*sys->player->yaw)

# define MIN(a,b) (((a) < (b)) ? (a) : (b))
# define MAX(a,b) (((a) > (b)) ? (a) : (b))
# define ABS(a) ((a) < 0 ? -(a) : (a))
# define M1(a)		((a) - 1)

# define CLAMP(a, mi, ma) MIN(MAX(a, mi), ma)
# define SIGN(v) (((v) > 0) - ((v) < 0))
# define VXS(x0,y0, x1,y1) ((x0)*(y1) - (x1)*(y0))
# define MAX_QUEUE 32

/*
**CUSTOM DEFINES
*/

# define PP player->pos
# define KEY ev.key.keysym.sym
# define SQ(a) (a*a)
# define PW player->where
# define PV player->velocity
# define SS sys->sectors
# define SEV sector->vertex
# define SW sys->window
# define SDSC sys->dscreen
# define IS_SDL_KD (ev.type == SDL_KEYDOWN)
# define HUD sys->hud
# define MENU sys->menu
# define SP sys->player
# define REND sys->renderer
# define FAKE sys->fake_surface
# define SEC_V sect->vertex
# define SDSCS sys->dscreen.item

#endif
