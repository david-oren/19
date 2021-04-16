/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:02:45 by daoren            #+#    #+#             */
/*   Updated: 2021/04/02 15:53:42 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Cette fonction recherche la dernière occurrence du caractère passé en second paramètre dans la chaîne de caractères spécifiée via le premier paramètre.

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen((char *)s);					// On égale i à la longueur de la chaine pour commencer à scanner par la fin
	if ((unsigned char)c == 0)					// Dans le cas où c serait un null terminating char on renvoie le pointeur NULL
		return ((char *)s + ft_strlen((char *)s));
	while (i--)							// on décrément i 
		if (s[i] == (unsigned char)c)				// Dans le cas on l'on rencontre un char qui correspond à c dans string s, on return le pointeur vers le char correspondant dans s
			return ((char *)s + i);
	return (0);
}
