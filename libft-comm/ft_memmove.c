/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:02:20 by daoren            #+#    #+#             */
/*   Updated: 2021/04/09 00:44:38 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Cette fonction permet de copier un bloc de mémoire spécifié par le paramètre source dans un nouvel emplacement désigné par le paramètre destination. 
// On peut donc dire que cette fonction est proche de la fonction memcpy. Néanmoins, la différence réside dans le fait que la fonction memmove accepte que les deux
// zones de mémoire puissent se chevaucher.

// En cas de chevauchement, la copie se passe comme si les octets de la zone source étaient d'abord copiés dans une zone temporaire, qui ne chevauche aucune des deux 
// zones pointées par source et destination, et les octets sont ensuite copiés de la zone temporaire vers la zone de destination.

void	*ft_memmove(void *b, const void *a, size_t n)
{
	unsigned char	*src;				
	char			*dest;
	int				i;

	i = -1;
	src = (unsigned char *)a;			// On cast la source en unsigned char *
	dest = (char *)b;
	if (a == 0 && b == 0)				// Si les deux strings sont vides on renvoie NULL
		return (NULL);
	else if (dest > (char *)src)			// Dans le cas où la dest est plus grande que la source, donc qu'on ne doit pas gérer de chevauchement
	{
		while (n > 0)				// Tant que n est suppérieur à 0 on décrémente et on copie les char de src vers dest
		{
			--n;
			dest[n] = src[n];
		}
	}
	else if (dest <= (char *)src)			// Si la dest est plus petite ou égale à la source, chevauchement
	{
		while ((size_t)++i < n)			// On incrément avec un i et on copie également la source vers la dest mais en commençant par les premiers chars jsuq'à n.
			dest[i] = src[i];
	}
	return (dest);
}

// Quand t'as une string et que tu veux la bouger quelque part, deux possibilités memmove ou memcpy
// Il faut voir si la zone mémoire de la dest ou tu vas cpier ta source, s'il y deux zones mémoires identiques tu vas avoir un conflit de mémoire.
// Si une des zone mémmoire de destination est identique à celle de sources, memmove pourra gérer alors que memcpy ne peut pas, s'il y a déjà un i, memmove va conserver le i et remplacer les char différents

