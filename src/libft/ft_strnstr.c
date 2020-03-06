/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 05:19:47 by osak              #+#    #+#             */
/*   Updated: 2017/12/21 21:07:57 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	char	*cbig;

	if (!*little)
		return ((char*)big);
	if (big == little)
		return ((char*)big);
	cbig = (char *)big;
	while (*big)
	{
		i = 0;
		while (big[i] == little[i] && big[i] != 0)
			i++;
		if (!little[i])
			break ;
		big++;
	}
	if (*big == 0)
		big = 0;
	if ((big - cbig) + ft_strlen(little) > len)
		return (0);
	return ((char *)(big));
}
