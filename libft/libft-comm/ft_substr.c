/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:31:00 by daoren            #+#    #+#             */
/*   Updated: 2021/04/13 16:01:15 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// substr est une fonction qui permet de copier une partie d une string avec comme variables la string,
// le point de depart a partir duquel on va copier la string et la longueur de la string
// La fonction renvoi la substring a la position de debut donne par start ou plus petite si la longueur 
// de la chaîne d'origine est inférieure à début + longueur, ou si la longueur est supérieure à MAXSTRINGLEN).

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;			// size_t correspond à un unsigned int avec au moins 16 bits, il ne peut pas contenir de valeur négative. 
	char	*str;			// size_t peut aussi contenir n'importe quel index de tableau. On ne veut jamais une valeure négative en index de tableau d'où le size_t

	i = 0;
	if (!s)							//protection de s
		return (NULL);
	if (start > ft_strlen(s)) 		//si le start est plus grand que la string
		return (ft_strdup(""));
	if (len + start > ft_strlen(s))		// pour etre sur de malloc la place necessaire si il y a trop de place par rapport a ce qu il faut copier
		len = ft_strlen(s) - start;	// on initialise len pour qu il ai la place exacte de ce qu il faut copier
	str = malloc(sizeof(char const) * len + 1);  // on alloue la memoire sans oublier le \0
	if (!str)			// protection au cas ou str n existe pas on renvoi NULL
		return (NULL);
	while (i < len && s[start])		//tant que l endroit ou on est dans la string est plus petit que la langueur 
		str[i++] = s[start++];		// de la string et que le start est dans la string alors on increment pour prendre tout la partie de string qu on veut copier
	str[i] = '\0';				// on met le \0 a la fin de la string qu on veut copier
	return (str);
}
