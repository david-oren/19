/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 22:05:11 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:01:29 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int destsize;

	if (min < max)
		destsize = max - min;
	else
	{
		*range = (NULL);
		return (0);
	}
	if (!(*range = malloc(destsize * sizeof(int))))
		return (-1);
	i = -1;
	while (++i < destsize)
	{
		(*range)[i] = min + i;
	}
	return (destsize);
}
