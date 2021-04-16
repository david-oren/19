/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:30:57 by daoren            #+#    #+#             */
/*   Updated: 2021/04/15 01:11:30 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//supprime les espaces blancs de début et de fin de str et renvoie le résultat sous la forme d une nouvelle str.
// Cependant, strtrim ne supprime pas les caractères d'espace blanc significatifs. Par exemple,
//strtrim supprime les espaces de début et de fin et les caractères de tabulation, 
//mais ne supprime pas le caractère d'espace au milieu.
// la fct renvoi .......................................

#include "libft.h"

static int	ft_check(char a, const char *set)		// une fct qui va checker si le caractere est un espace
{
	while (*set)
		if (a == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;		// variable d iteration 
	int		j;		//.............

	if (!s1 || !set)		// une protection si soit la string soit ........ est inexistant
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;					// "j"Il commence à la fin Du "s1" Car il est positionné de base à la fin avec le j = strlen
	while (s1[i] && ft_check(s1[i], set))	// Bah le 1er while set à incrementer le "i" Pour qu'il soit mis à la position du 1er character qui correspond au "set"
		++i;								//Sauf s'il y en a pas et là il va juskà la fin de s1
	while (j > i && ft_check(s1[j], set))	// le while fait décrémenter le j juskà tomber sur "i" OU juskà tomber sur un character qui se trouve dans "set"
		--j;
	return (ft_substr(s1, i, (j - i + 1)));	// Et finalement, le programme va retourner l'interieur entre i et j ------ 
}											//j - i + 1D'abord on dit a partir d'ou Le "i" Ensuite on est sensé dire "combien de caractere on prend"
											//Et ca donne bien ce qu'on need
