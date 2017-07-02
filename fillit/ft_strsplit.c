/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:57:03 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 16:57:03 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	size;
	char	**p;
	size_t	start;

	i = 0;
	size = 0;
	p = (char **)malloc((ft_nb_split_word(s, c) + 1) * sizeof(char *));
	if (p == NULL || s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			p[size++] = ft_strsub(s, start, i - start);
		}
	}
	p[size] = NULL;
	return (p);
}
