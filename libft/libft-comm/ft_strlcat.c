/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:02:32 by daoren            #+#    #+#             */
/*   Updated: 2021/04/02 14:50:31 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Cette fonction permet de rajouter à une chaîne de caractères déjà existante le contenu d'une seconde. Autrement dit de concaténer les contenu de deux chaînes de caractères, 
// mais le résultat sera stocké dans la première chaîne passé en paramètre (aucune nouvelle chaîne ne sera produite). Bien entendu le bloc de mémoire devant recevoir le contenu 
// à concaténer doit être alloué de manière à être suffisament grand pour contenir la totalité des deux chaînes caractères.
// L'argument dstsize, correspond à la longueur de la destination après la concaténation. En utilisant cette valeur on évite l'overflow qui peut arriver lorsque l'on utilise strcat

// On ajoute src à la suite de dst

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;						// size_t, opérateur unsigned, on l'utilise pour une longueur donc on a pas besoin de valeur négative

	i = -1;							// On initalise à i = -1 car on utilise un ++i plus tard
	len = ft_strlen(dst);
	if (dstsize <= len)					// Dans le cas où la longueur de dst avant concaténation est plus grand ou égal à dstsize
		return (ft_strlen(src) + dstsize);
	while (src[++i] && i < dstsize - len - 1)
		dst[len + i] = src[i];				// Concaténation, on démarre à dst[len+i] et on égale chacun de char qui suit à la valeur de src[i].
	dst[len + i] = 0;					// Le dernier char est égale à \0
	return (len + ft_strlen(src));
}								// dst est modifié à la fonction retourne la longueur de totale de ft_strlen(dst) / ft_strlen(src)
