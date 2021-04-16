/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:02:28 by daoren            #+#    #+#             */
/*   Updated: 2021/04/09 00:48:40 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Cette fonction permet de dupliquer une chaîne de caractères.


char	*ft_strdup(const char *s1)
{
	char	*new_s1;
	int		i;

	i = ft_strlen(s1) + 1;					// Il faut connaître la longueur de la string
	new_s1 = (char *)malloc(sizeof(char) * i);		// Malloc comme d'hab, on ajoute le + 1 à la ligne précédente pour le \0
	if (!(new_s1))
		return (0);
	ft_memcpy(new_s1, s1, i);				// On utilise memcpy pour pouvoire copier la string dans la dest avec la longueur i
	return (new_s1);
}
