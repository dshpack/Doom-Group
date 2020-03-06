/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 04:35:57 by osak              #+#    #+#             */
/*   Updated: 2017/12/04 15:57:08 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	if (src < dst)
	{
		while (src - 1 != src + n - 1 - i)
		{
			*(unsigned char *)(dst + n - 1 - i) =
				*(unsigned char *)(src + n - 1 - i);
			i++;
		}
	}
	if (src > dst)
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	return (dst);
}
