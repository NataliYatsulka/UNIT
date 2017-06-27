/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:33:13 by nyatsulk          #+#    #+#             */
/*   Updated: 2016/11/30 11:33:13 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	int				k;
	char			*p;

	if (s == NULL)
		return (NULL);
	i = 0;
	k = ft_strlen(s);
	while (k && (s[k - 1] == ' ' || s[k - 1] == '\n' || s[k - 1] == '\t'))
		k--;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		i++;
		k--;
	}
	if (k < 0)
		k = 0;
	p = ft_strsub(s, i, (size_t)k);
	return (p);
}
