/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 05:15:59 by osak              #+#    #+#             */
/*   Updated: 2017/12/21 18:55:54 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

int		ft_strncmp(const char *string1, const char *string2, size_t n)
{
	if (!n)
		return (n);
	while ((*string1 == *string2) && *string1 && *string2 && n > 1)
	{
		string1++;
		string2++;
		n--;
	}
	return ((unsigned char)*string1 - (unsigned char)*string2);
}
