/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:02:24 by daoren            #+#    #+#             */
/*   Updated: 2021/04/12 21:01:40 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = -1;
	if ((unsigned char)c == '\0')
		return ((char *)s + ft_strlen((char *)s));
	while (s[++i])
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
	return (NULL);
}
