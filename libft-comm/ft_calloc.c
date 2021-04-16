/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:01:55 by daoren            #+#    #+#             */
/*   Updated: 2021/04/13 16:09:03 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Alloue de la mémire et renvoie un pointeur vers la mémoire qu'on a alloué

// Cette fonction alloue un bloc de mémoire en initialisant tous ces octets à la valeur 0. Bien que relativement proche de la fonction malloc, deux aspects les différencient :

// - L'initialisation : calloc met tous les octets du bloc à la valeur 0 alors que malloc ne modifie pas la zone de mémoire.
// - Les paramètres d'appels : calloc requière deux paramètres (le nombre d'éléments consécutifs à allouer et la taille d'un élément) 
// alors que malloc attend la taille totale du bloc à allouer.
// elle renvoi un pointeur de memoire ou la valeur null 

void	*ft_calloc(size_t count, size_t size)
{
	void	*m;

	m = malloc(size * count);		// Toujours protéer un malloc en protégeant l'expace nécessaire à la résolution de la fonction. 
						// En général on ne dit pas de quelle place mémoire on besoin, ici on a deux variable count et size 
						// Pour allouer assez de mémoire, on fait size * count pour être sûr de ne pas manquer de place
						// Obligatoire de toujours protéger le malloc. 
						// Sinon un autre processus peut utiliser la mémoire utilisé par la fonction et changer la valeur stockée en.
	if (!m)		
		return (NULL);			// Protection, on retourne NULL dans le cas où il n'y a pas de mémoire allouée.
	ft_bzero(m, size * count);	
	return (m);				// On utilise bzero pour réinitialiser m et on retourne m qui correspond renvoie le pointeur vers la mémoire qu'on alloue.
						// On utilise calloc pour être sûr que la mémoire a bien été réinitialisée.
}
