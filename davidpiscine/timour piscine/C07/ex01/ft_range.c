/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 21:29:42 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:01:27 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int i;
	int *dest;
	int destsize;

	if (min < max)
		destsize = max - min;
	else
		return (NULL);
	if (!(dest = malloc(destsize * sizeof(int))))
		return (NULL);
	i = -1;
	while (++i < destsize)
	{
		dest[i] = min + i;
	}
	return (dest);
}
