/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:30:51 by daoren            #+#    #+#             */
/*   Updated: 2021/04/02 11:59:24 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Joindre deux strings ensemble

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	size;						// size_t est un opérateur non signé qui correspond à unsigned int, comme c'est une taille on a pas besoin de valeur négative

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;		// Taille = longueur des deux chaîne + \0
	dest = (char *)ft_calloc(sizeof(char), size);		// Allocation de mémoire, en utilisant calloc à la place de malloc parce-que, ici on a besoin que chaque octet ait la valeur alors que malloc ne modifie pas la zone mémoire.
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s1, ft_strlen(s1));			// On utilise la fonction memcopy pour insérer s1 dans dest en utilisant sa longueur
	ft_memcpy(dest + ft_strlen(s1), s2, ft_strlen(s2));	// Si s1 fait 6 charactrèes de long, tu pourrais écrire dest + 6 à la place dest + ft_strlen(s1), ça fonctionne aussi
	return (dest);						// C'est un peu de la magie noire mais ça marche !
}
