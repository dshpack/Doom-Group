/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 04:57:36 by osak              #+#    #+#             */
/*   Updated: 2017/12/04 16:59:33 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l;
	char	*str;
	int		i;
	int		z;

	i = 0;
	z = 0;
	if (!s1 || !s2)
		return (0);
	l = ft_strlen(s1) + ft_strlen(s2);
	str = ft_strnew(l);
	if (str && s1 && s2)
	{
		while (s1[i] != 0)
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[z] != 0)
			str[i++] = s2[z++];
		return (str);
	}
	else
		return (NULL);
}
