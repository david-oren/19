/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 03:03:33 by daoren            #+#    #+#             */
/*   Updated: 2021/04/13 02:18:20 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Cette fonction permet de remplir une zone mémoire, identifiée par son adresse et sa taille, avec une valeur précise.

void	*ft_memset(void *b, int c, size_t n)
{
	char	*str;					// On initialise le pointeur de str

	str = (char *)b;				// On caste le b pour le transformer en char (et non plus un void). On lui donne une définition de variable
	while (b && n > 0)				// Boucle while ou tu verifie si le b existe (protection pour NULL) puis l'on commence par le nombre d'octet maximum que l'on va remplacer
		str[--n] = c;				// On remplace chaque char de str par le paramètre c
	return (b);						// On retourne le pointeur pointeur b
