/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:45:46 by daoren            #+#    #+#             */
/*   Updated: 2021/04/14 19:23:15 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Prend en paramètre l’adresse d’un pointeur sur un maillon sans faire le relink et libère la mémoire du contenu 
//de ce maillon avec la fonction del passée en paramètre puis libère la mémoire du maillon en lui même avec free(3). 
//La mémoire du champ next ne doit en aucun cas être libérée. Pour terminer, le pointeur sur le maillon maintenant libéré 
//doit être mis à NULL.

#include "libft.h"

void	ft_lstdelone(t_list *alst, void (*del)(void*))	//Le deuxieme parametre attends une fonction qui ne renvoie rien et qui prend un ptr sur void en argument
{
	if (!del || !alst)
		return ;
	del(alst->content);		// delete le dernier element de la variable content 
	free(alst);				// on free le maillon
}
