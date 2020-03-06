/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 05:26:08 by osak              #+#    #+#             */
/*   Updated: 2017/11/21 10:58:58 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret_str;

	ret_str = ft_strnew(len);
	if (ret_str && s)
		ft_memmove(ret_str, s + start, len);
	return (ret_str);
}
