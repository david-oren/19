/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:02:20 by daoren            #+#    #+#             */
/*   Updated: 2021/04/09 00:44:38 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *b, const void *a, size_t n)
{
	unsigned char	*src;
	char			*dest;
	int				i;

	i = -1;
	src = (unsigned char *)a;
	dest = (char *)b;
	if (a == 0 && b == 0)
		return (NULL);
	else if (dest > (char *)src)
	{
		while (n > 0)
		{
			--n;
			dest[n] = src[n];
		}
	}
	else if (dest <= (char *)src)
	{
		while ((size_t)++i < n)
			dest[i] = src[i];
	}
	return (dest);
}
