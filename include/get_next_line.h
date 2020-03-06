/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 11:41:42 by osak              #+#    #+#             */
/*   Updated: 2018/04/19 16:09:29 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10000000

# include <stdio.h>
# include <fcntl.h>
# include "../src/libft/inc/libft.h"
# include <zconf.h>
# include <stdlib.h>
# include "player_stable.h"

int get_next_line(const int fd, char **line);

#endif
