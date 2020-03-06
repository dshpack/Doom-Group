/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 01:39:25 by osak              #+#    #+#             */
/*   Updated: 2017/11/21 13:19:40 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

int		ft_isprint(int c)
{
	if (c < 127 && c > 31)
		return (1);
	else
		return (0);
}
