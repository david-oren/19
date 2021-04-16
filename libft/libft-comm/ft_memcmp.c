/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:02:10 by daoren            #+#    #+#             */
/*   Updated: 2021/04/02 15:50:20 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// On compare deux strings sur une longueur n et dès qu'elles ne sont plus identiques, on renvoie la différence deux char en nombres ASCII

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;			// On cast les deux chaînes de character qui étaient en void vers des string.
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	if (!(n))				// Dans le cas où n n'existe pas on renvoie 0
		return (0);
	while (i < n && p1[i] == p2[i])		// Tant que i est plus petit que n et que les char des deux strings sont identiques, on avance
		i++;
	if (i == n)				// Quand on atteint l'indice n dans les strings, on retourne au char précédent dans la string
		i--;				// 
	return (p1[i] - p2[i]);
}

// Petit soucis par rapport à la vraie fonction si un des deux string fait 4 chars de long et qu'on a n  > 4
