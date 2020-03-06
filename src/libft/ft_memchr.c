/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 04:32:26 by osak              #+#    #+#             */
/*   Updated: 2017/12/21 18:53:41 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n != 0)
	{
		if (*(unsigned char*)s == (unsigned char)c)
			return ((unsigned char*)s);
		s++;
		n--;
	}
	return (0);
}
