/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:45:48 by daoren            #+#    #+#             */
/*   Updated: 2021/04/14 19:18:15 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Parcourt la liste lst en appliquant à chaque content dans la liste chaine la fonction f.


#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *)) 		//*lst = Pointeur sur le premier maillon d’une liste.
{														// le deuxieme param L’adresse d’une fonction à laquelle appliquer chaque maillon de la liste.
	while (lst && f)
	{
		f(lst->content);								// on veut qu il checke dans la memoire lst et on y applique notre fct sur chaque element de content
		lst = lst->next;								//on donne la valeur de next dans notre memoire liste
	}
}
