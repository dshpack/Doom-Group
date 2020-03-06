/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:06:09 by olaktion          #+#    #+#             */
/*   Updated: 2019/06/10 13:06:49 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

t_bool				ft_isint(const char *str, t_bool strict)
{
	unsigned int	res;
	unsigned int	border;
	int				i;
	int				sign;
	int				digits;

	i = 0;
	res = 0;
	digits = 0;
	border = (unsigned int)(FT_INT_MAX / 10);
	while (strict && ft_isspace(str[i]))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) && ++digits)
	{
		if (((res > border || (res == border && (str[i] - '0') > 7))
			&& sign == 1)
			|| ((res > border || (res == border && (str[i] - '0') > 8))
				&& sign == -1))
			return (false);
		res = res * 10 + (str[i++] - '0');
	}
	return (!str[i] && digits);
}
