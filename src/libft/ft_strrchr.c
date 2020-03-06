/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 05:22:26 by osak              #+#    #+#             */
/*   Updated: 2017/12/21 20:02:09 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	ssize_t	i;

	i = ft_strlen(s) - 1;
	while (i > -1)
	{
		if (s[i] == (char)c)
			return (char *)(s + i);
		i--;
	}
	if (!c)
		return ((char *)(s + ft_strlen(s)));
	return (0);
}
