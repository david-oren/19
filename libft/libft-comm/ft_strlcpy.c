/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:02:36 by daoren            #+#    #+#             */
/*   Updated: 2021/04/11 18:21:06 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// On copie la valeur de src dans dst avec comme longueur max dstsize et on retourne la longueur totale de la string qu'on essaye de créer.

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;			// size_t correspond à un unsigned int avec au moins 16 bits, il ne peut pas contenir de valeur négative. 
						// size_t peut aussi contenir n'importe quel index de tableau. On ne veut jamais une valeure négative en index de tableau d'où le size_t
	size_t	x;

	if (!dst || !src)
		return (0);
	x = 0;
	while (src[x])						// Sur la longueur de src, on incrémente x, qui va correspondre à sortie de la fonction.
		x++;
	if (!(dstsize))
		return (x);
	i = -1;
	while (src[++i] && i < dstsize - 1)			// Pour toute la string src à condition que i soit inférieur à dstsize - \0
		dst[i] = src[i];				// On égale dst[i] à src[i], copie.
	dst[i] = '\0';	
	return (x);
}								// dst contient les dstsize premier chars de src et la fonction retourne la longueur x qui correspond à la longueur de src.
