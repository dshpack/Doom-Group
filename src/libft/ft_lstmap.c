/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:50:31 by osak              #+#    #+#             */
/*   Updated: 2017/12/21 18:27:50 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*ret_last;

	ret = 0;
	if (f && lst)
	{
		ret = f(lst);
		ret_last = ret;
		lst = lst->next;
		while (lst)
		{
			ret_last->next = f(lst);
			ret_last = ret_last->next;
			lst = lst->next;
		}
	}
	return (ret);
}
