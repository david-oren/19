/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:02:41 by daoren            #+#    #+#             */
/*   Updated: 2021/04/11 19:48:15 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//La fonction strnstr() cherche la première occurrence de la sous-chaîne aiguille au sein de la chaîne meule_de_foin. Les caractères « \0 » de fin ne sont pas comparés.
//et elle ne compare que les n (au plus) premiers caractères de s1 et s2.

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	char	*need;
	size_t	i;				// size_t est un opérateur non signé qui correspond à unsigned int, comme c'est une taille on a pas besoin de valeur négative
	size_t	len_need;		// int, comme c'est une taille on a pas besoin de valeur négative

	hay = (char *)haystack;	// on caste nos 2 variables car on a besoin de modifier ces variables
	need = (char *)needle;
	i = 0;
	if (need[i] == '\0')	// si on est a la fin de need on retourne hay
		return (hay);
	len_need = ft_strlen(need);  // on prevoit de la place dans len_need en calculant len de need
	while (hay[i] && len_need <= len) // tant qu on est dans hay et que la longueur de l'aiguille est inférieure à la la longueur len passé en paramètre.
	{
		if (hay[i] == *need && ft_memcmp(&hay[i], need, len_need) == 0) 			// Si le char de hay correspond à need, on utilise memcmp entre hay et need
			return (&hay[i]);								// Si on trouve une correspondance on renvoie le char correspondant dans hay
		i++;											// Dans le cas contraire on écrémente i
		len--;											// On décrémente len car en avançant dans la chaîne et on besoin d'un len de plus en pus petit dans mempy
	}
	return (NULL);										//.............
}
