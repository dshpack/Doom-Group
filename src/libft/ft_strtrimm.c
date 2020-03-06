/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:56:55 by osak              #+#    #+#             */
/*   Updated: 2017/11/21 10:57:08 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strtrimm(char const *s, char c)
{
	int		i;
	size_t	l;
	char	*strres;

	i = 0;
	if (s)
	{
		while ((s[i] == c) && s[i])
			i++;
		l = ft_strlen(s) - 1;
		while ((s[l] == c) && s[l] && (l > i - 1))
			l--;
		l = l - i + 1;
		strres = ft_strnew(l);
		ft_memmove(strres, s + i, l);
		return (strres);
	}
	return (NULL);
}
