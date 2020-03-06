/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 11:41:38 by osak              #+#    #+#             */
/*   Updated: 2018/04/19 14:07:21 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				check_newline(char *buff, char **line)
{
	char		*n_pos;
	char		*old_line;

	if (!*buff)
		return (0);
	n_pos = ft_strchr(buff, '\n');
	if (n_pos)
		*n_pos = 0;
	old_line = *line;
	*line = ft_strjoin(*line, buff);
	if (n_pos)
		ft_strcpy(buff, n_pos + 1);
	else
		buff[0] = 0;
	free(old_line);
	return (n_pos ? 1 : 0);
}

int				get_next_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE + 1] = {0};
	int			size;

	if (fd < 0 || !line)
		return (-1);
	*line = ft_strnew(0);
	if (!check_newline(buff, line))
		while (1)
		{
			size = read(fd, buff, BUFF_SIZE);
			if (size < 1)
			{
				if (**line)
					return (1);
				return (size);
			}
			buff[size] = '\0';
			if (check_newline(buff, line))
				return (1);
		}
	return (1);
}
