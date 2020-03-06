/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:50:23 by osak              #+#    #+#             */
/*   Updated: 2017/11/21 14:36:54 by osak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

static int	word_count(const char *s, char c)
{
	int		i;
	int		n;
	char	*str;

	n = 0;
	i = 0;
	str = (char *)s;
	if (!s || !c)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] == c)
		{
			if (str[i + 1] == '\0')
				return (n);
			i++;
		}
		n++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (n);
}

static char	*cut_dilims(const char *s, size_t *k, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[*k] == c)
		*k += 1;
	i = *k;
	while (str[*k])
	{
		if (str[*k] == c)
			break ;
		*k += 1;
	}
	return (ft_strsub(str, i, *k - i));
}

char		**ft_strsplit(const char *s, char c)
{
	int		i;
	size_t	k;
	int		n;
	char	*str;
	char	**str_s;

	i = 0;
	n = 0;
	k = 0;
	n = word_count(s, c);
	str = (char *)s;
	str_s = (char **)malloc(sizeof(char *) * (n + 1));
	if (str_s == NULL)
		return (NULL);
	while (i < n)
	{
		str_s[i] = cut_dilims(str, &k, c);
		i++;
	}
	str_s[i] = NULL;
	return (str_s);
}
