/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 02:32:30 by daoren            #+#    #+#             */
/*   Updated: 2021/04/15 01:58:17 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(int i, char **dest)				//fonction pour free l espace necessaire dans dest
{
	while (i)
		free(dest[--i]);					// On utilise la fonction, on y a droit d'après les consignes
	free(dest);
}

static int	ft_strlen_remix(char const *s, char c)			//un strlen qui doit prendre en compte le delimitateur, char c
{
	int	i;

	i = 0;
	while (s && s[i] && s[i] != c)					// On incrémente tant que la string existe et que le char est différence de c
		i++;
	return (i);
}

static int	ft_word_number(char const *s, char c)			// une fonction afin de compter le nombre de mots. w etant le nbr de mot total
{															// il faut incrementer tant que la str existe et que le caractere soit ou non = au delimatateur
	int	i;													// tant que s existe alors on increment w et on retourne w
	int	w;

	w = 0;
	i = 0;									// Par exemple si on entre un espace comme déliminateur, on va compter toutes les sous les sub string séparées par des espaces, qui correspondent au mots
	while (s && s[i])						// Protection, normalement ça marche en utilisant juste s[i], mais c'est de mettre s et s[i] dans le doute.
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			w++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (w);
}

char	**ft_split(char const *s, char c)				// une variable pour la destination, une variable pour avoir le nombre de mots et une variable pour se balader dans la string
{
	char	**dest;
	int		wnb;
	int		i;

	wnb = ft_word_number(s, c);					// on va utiliser la fct word number avec la variable wnb
	dest = (char **)malloc(sizeof(char *) * (wnb + 1));		// on alloue de la memoire a dest en tenant compte du \0
	if (!dest)							// Protection, si il n y a rien a la dest il faut return null
		return (NULL);						
	i = 0;
	while (i < wnb)						// tant que quand on se balade dans la source i est < au nombre de mot
	{								// tant que la source existe et qu on soit au caractere delimateur alors on va au mot d apres
		while (s && *s && *s == c)
			s++;
		dest[i] = ft_substr(s, 0, ft_strlen_remix(s, c));	// on va utiliser la fct substr pour prendre le morceau de la string de source pour la mettre dans dest 
		if (!dest)						// dans substr on a besoin de notre strlen perso pour avoir le nombre de caractere a prendre
		{							
			ft_free(i, dest);				// si dest n existe pas alors il faut liberer l espace et retourner null
			return (NULL);					// Et on return NULL
		}
		s += ft_strlen_remix(s, c);				//  c est un pointeur sur string et il faut le deplacer sur une distance de strlenremix, pour avancer dans la source
		i++;
	}
	dest[i] = 0;							//il faut que dest arrive a son nul terminiting caractere
	return (dest);
}
