/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:02:00 by daoren            #+#    #+#             */
/*   Updated: 2021/04/13 01:30:02 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned const char	*psrc;
	unsigned char		*pdst;

	i = -1;
	psrc = (unsigned const char *)src;
	pdst = (unsigned char *)dst;
	if (!(n))
		return (NULL);
	while (++i < n)
	{
		*(pdst + i) = *(psrc + i);
		if (*(psrc + i) == (unsigned char)c)
			return ((void *)dst + i + 1);
	}
	return (NULL);
}
