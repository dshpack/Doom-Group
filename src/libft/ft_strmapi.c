/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 05:13:34 by osak              #+#    #+#             */
/*   Updated: 2017/12/04 16:57:24 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*string;
	size_t			i;
	unsigned int	n;

	n = 0;
	if (!s)
		return (0);
	i = ft_strlen(s);
	string = ft_strnew(i);
	if (string)
	{
		while (s[n] != 0 && n <= i)
		{
			string[n] = f(n, s[n]);
			n++;
		}
	}
	return (string);
}
