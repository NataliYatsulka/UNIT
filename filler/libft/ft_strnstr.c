/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:50:28 by nyatsulk          #+#    #+#             */
/*   Updated: 2016/11/28 16:11:05 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		len_a;
	size_t	len_b;
	int		lenb_buff;

	len_b = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[len_b] != '\0' && len_b < len)
	{
		len_a = 0;
		lenb_buff = len_b;
		while (big[len_b] == little[len_a] && len_b < len)
		{
			len_a++;
			len_b++;
			if (little[len_a] == '\0')
				return ((char *)&big[lenb_buff]);
		}
		len_b = lenb_buff;
		len_b++;
	}
	return (NULL);
}
