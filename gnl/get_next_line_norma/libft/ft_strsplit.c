/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:14:57 by nyatsulk          #+#    #+#             */
/*   Updated: 2016/11/30 18:14:57 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
