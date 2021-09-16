/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:02:05 by daoren            #+#    #+#             */
/*   Updated: 2021/04/13 01:29:55 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new_s;
	unsigned char	new_c;
	size_t			i;

	new_s = (unsigned char *)s;
	new_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (new_s[i] == new_c)
			return (&new_s[i]);
		i++;
	}
	return (NULL);
}
