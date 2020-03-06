/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:36:05 by osak              #+#    #+#             */
/*   Updated: 2017/12/04 15:55:37 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

int	ft_strcmp(const char *string1, const char *string2)
{
	while ((*string1 == *string2) && *string1 && *string2)
	{
		string1++;
		string2++;
	}
	return ((unsigned char)*string1 - (unsigned char)*string2);
}
