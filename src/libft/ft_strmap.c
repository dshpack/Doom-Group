/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 05:12:46 by osak              #+#    #+#             */
/*   Updated: 2017/12/04 16:56:53 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*string;
	size_t	i;
	size_t	n;

	n = 0;
	if (!s)
		return (0);
	i = ft_strlen(s);
	string = ft_strnew(i);
	if (string)
	{
		while (s[n] != 0 && n <= i)
		{
			string[n] = f(s[n]);
			n++;
		}
	}
	return (string);
}
