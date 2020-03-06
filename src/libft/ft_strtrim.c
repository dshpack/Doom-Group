/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 05:26:54 by osak              #+#    #+#             */
/*   Updated: 2017/11/21 16:00:11 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	l;
	char	*strres;

	i = 0;
	if (s)
	{
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
			i++;
		l = ft_strlen(s) - 1;
		while ((s[l] == ' ' || s[l] == '\n' ||
	s[l] == '\t') && s[l] && (l > i - 1))
			l--;
		l = l - i + 1;
		strres = ft_strnew(l);
		if (strres)
			ft_memmove(strres, s + i, l);
		return (strres);
	}
	return (NULL);
}
