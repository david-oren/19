/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:02:00 by daoren            #+#    #+#             */
/*   Updated: 2021/04/13 16:42:08 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


// Copie n octet de la zone mémoire source vers la zone mémoire destination, elle s'arrêt dès qu'elle rencontre le char c, ce qui permet de copier une partie juqu'à un certain c.
// La fonction renvoie un pointeur vers le char immédiatement après c dans la destination.
// Dans le cas où elle ne trouve c dans le n premiers char de source, elle renvoie NULL

// La fonction memccpy() copie au plus n octets de la zone mémoire src vers la zone mémoire dest, s'arrêtant dès qu'elle rencontre le caractère c.  

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;	// size_t correspond à un unsigned int avec au moins 16 bits, il ne peut pas contenir de valeur négative. 
						// size_t peut aussi contenir n'importe quel index de tableau. On ne veut jamais une valeure négative en index de tableau d'où le size_t
	unsigned const char	*psrc;		// Pointeur de la source
	unsigned char		*pdst;		// Pointeur de la dest

	i = -1;
	psrc = (unsigned const char *)src; // const car on ne va pas modifier la source
	pdst = (unsigned char *)dst;	// on utlise unsigned car c est de 0 a 255  et donc dans la memoire on ne va jms utiliser de negatif donc on emploi unsigned char	psrc = (unsigned const char *)src;		
	if (!(n))						// si y a pas de nombre d octet precise on renvoit null protection
		return (NULL);
	while (++i < n)					// tant que le nbr d octet a copie est superieur a l indice auxquel on est 
	{
		*(pdst + i) = *(psrc + i);			// on se positionne  au meme indice a la src et a la dest pour copier la zone memoire
		if (*(psrc + i) == (unsigned char)c)	// si on arrive a la zone memoire du delimitateur
			return ((void *)dst + i + 1);	// on retourne la zone memoire de dest qui est caster en void avec la memoire de i + la fin de string
	}
	return (NULL);		// si y a rien on renvoi NULL
}
