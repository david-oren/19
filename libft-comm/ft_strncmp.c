/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:55:41 by daoren            #+#    #+#             */
/*   Updated: 2021/04/11 18:56:52 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//La fonction strncmp() compare les deux chaînes s1 et s2 et elle ne compare que les n (au plus) premiers caractères de s1 et s2.   Elle renvoie un entier négatif, nul, ou positif, si s1 est respectivement inférieure, égale ou supérieure à s2.
//Les fonctions strncmp() renvoient un entier inférieur, égal ou supérieur à zéro si s1 (ou ses n premiers octets) est respectivement inférieure, égale ou supérieure à s2.  

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;   	// size_t correspond à un unsigned int avec au moins 16 bits, il ne peut pas contenir de valeur négative. 
					// size_t peut aussi contenir n'importe quel index de tableau. On ne veut jamais une valeure négative en index de tableau d'où le size_t

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (i < n))  //Tant que on compare les meme indices et que on est pas a la fain de la str 1 et que i est plus petit que n
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);  // on caste nos string en unsigned car on a pas besoin de retourner de nbr neg
}
