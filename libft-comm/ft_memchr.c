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

// Recherche la première occurence d'une valeur typée int, mais interprétée en tant que char, dans un bloc de mémoire. 
// Comme on traite un bloc de mémoire et non pas une chaîne de caractères AZT (à zéro terminal), nous devons aussi spécifier à la fonction la taille du bloc de mémoire
// dans lequel réaliser la recherche.

// On cherche la première occurrence d'int c dans une string s, on retourne l'adresse mémoire du char trouvé. &new_s[i]

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new_s;
	unsigned char	new_c;
	size_t			i;

	new_s = (unsigned char *)s;		// On égale new_s à la chaine de character s
	new_c = (unsigned char)c;		// Idem pour new_c avec l'int c, que l'on tranforme en char par la même occasion.
	i = 0;
	while (i < n)				// On scan la string s pendant n itération
	{
		if (new_s[i] == new_c)		// Dans le cas où le char de strin match avec new_c
			return (&new_s[i]);		// On retourne l'adresse mémoire trouvé au sein de la string s
		i++;
	}
	return (NULL);				// Si non trouvé en renvoie NULL.
}
