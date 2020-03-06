/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 04:46:44 by osak              #+#    #+#             */
/*   Updated: 2017/11/21 14:29:58 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	ft_putnbr_fd(int k, int fd)
{
	char			min;
	long long int	n;

	n = k;
	min = '-';
	if (n < 0)
	{
		write(fd, &min, 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
	else
	{
		n = n + '0';
		write(fd, &n, 1);
	}
}
