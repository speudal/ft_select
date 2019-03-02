/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 21:32:21 by tduval            #+#    #+#             */
/*   Updated: 2018/12/23 04:53:33 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	size_t	ft_count_words(char const *s, char c)
{
	size_t	ct;

	ct = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || !(*(s + 1))))
			ct++;
		s++;
	}
	return (ct);
}

static	size_t	ft_how_long(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	size_t	j;
	int		ct;
	char	**tab;

	i = -1;
	j = 0;
	if (!s)
		return (0);
	ct = ft_count_words(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (ct + 1))))
		return (0);
	while (++i < ct)
	{
		while (*s && *s == c)
			s++;
		if (!(tab[i] = (char *)malloc(sizeof(char) * (ft_how_long(s, c) + 1))))
			return (0);
		while (*s != c && *s)
			tab[i][j++] = *s++;
		tab[i][j] = '\0';
		j = 0;
	}
	tab[i] = 0;
	return (tab);
}
