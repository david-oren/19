/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:02:24 by daoren            #+#    #+#             */
/*   Updated: 2021/04/12 21:01:25 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Cette fonction recherche la première occurrence du caractère passé en second paramètre dans la chaîne de caractères spécifiée via le premier paramètre.

// Renvoie un pointeur sur la première occurence de la chaîne s et recherche la caractère dans la chaîne, ça renvoie un pointeur vers le caractère trouvé ou null s'il n'est pas trouvé.

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)					// protection si on envoi NULL
		return (NULL);
	i = -1;								// On commence à i = -1, car à dans la boucle while on utilise ++i 
	if ((unsigned char)c == 0)					// On cast le c en unsigned char à partir d'un int, on a besoin d'un char pour comparer à 0, on utilise unsigned 
									// pour pouvoir gérer tous les nombre de 0 à 255, donc toute la table ascii
		return ((char *)s + ft_strlen((char *)s));
	while (s[++i])
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
	return (NULL);
}

// Par exemple si on veut utiliser la fonction sur la string 'abcdefggghh' avec ft_strchr(s, 'd') on aura n sortie defggghh, soit la chaîne à partir de d compris, jusqu'au \0
// Si on inclus un /0 dans la chaîne on va segfault dans le cas où il précède le d, ou bien la fonction va s'arrêter avant la fin de la string s'il est placé après le d
