/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:28:59 by daoren            #+#    #+#             */
/*   Updated: 2021/04/12 23:00:09 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** Applique la fonction f a chaque caractere de la chaine de caracteres passee en argument pour creer
** une nouvelle chaine de caracteres
** elle renvoie la chaine de caracteres resultant des applications successives de f. Retourne NULL si l allocation echoue
*/ 
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))  // notion de pointeur sur fonction utile quand tu dois appliquer plein de fct sur un cas
{								// une fonction peut avoir une adresse memoire et donc si tu as un pointeur tu peux te deplacer d une fct a une autre
	char	*dest;
	int		i;

	if (!s || !f)		// protection si s ou f n existe pas
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dest)			// protection si dest n existe pas
		return (NULL);
	i = -1;
	while (s[++i])
		dest[i] = f(i, s[i]);  // va faire passer la fct f sur chaque caractere de la str de depart 
	dest[i] = '\0'; // rajoute le null byte a dest
	return (dest);
}
