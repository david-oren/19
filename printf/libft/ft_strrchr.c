/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:02:45 by daoren            #+#    #+#             */
/*   Updated: 2021/04/02 15:53:42 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen((char *)s);
	if ((unsigned char)c == 0)
		return ((char *)s + ft_strlen((char *)s));
	while (i--)
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
	return (0);
}
