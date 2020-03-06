/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 05:23:43 by osak              #+#    #+#             */
/*   Updated: 2017/12/04 15:53:50 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;

	if (!*little)
		return ((char*)big);
	if (big == little)
		return ((char*)big);
	while (*big)
	{
		i = 0;
		while (big[i] == little[i] && big[i] != 0)
			i++;
		if (!little[i])
			return ((char*)big);
		big++;
	}
	return (NULL);
}
