/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:18:18 by osak              #+#    #+#             */
/*   Updated: 2017/11/21 11:45:39 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	unsigned char	*str;

	str = (unsigned char*)memptr;
	while (num)
	{
		*str = val;
		num--;
		str++;
	}
	return (memptr);
}
