/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:46:00 by daoren            #+#    #+#             */
/*   Updated: 2021/04/14 19:12:24 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Alloue (avec malloc(3)) et retourne un maillon “frais”. Les champs content et content_size 
//du nouveau maillon sont initialisés par copie des paramètres de la fonction. Si le paramètre 
//content est nul, le champs content est initialisé à NULL et le champs content_size est initialisé 
//à 0 quelque soit la valeur du paramètre content_size. Le champ next est initialisé à NULL. Si l’allocation échoue, la fonction renvoie NULL.

#include "libft.h"

t_list	*ft_lstnew(void *content)		//Le contenu à ajouter au nouveau maillon.
{
	t_list	*new; //La taille du contenu à ajouter au nouveau maillon.

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)					//protection si new n existe pas
		return (NULL);
	new->content = content;		//sur le pointeur new dans la place content on lui donne la valeur de notre variable content
	new->next = 0;
	return (new);		//Le nouveau maillon.
}
