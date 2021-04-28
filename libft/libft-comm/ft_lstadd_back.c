/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:45:32 by daoren            #+#    #+#             */
/*   Updated: 2021/04/28 19:18:21 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// struc c est un tableau de variable de plusieurs types differents
// liste chaine a besoin d une structure pour fct. 
// liste va permettre de rassembler des information disperse dans la memoire --> exemple malloc ne va pas savoir rassembler ta memoire si entre ce que tu as besoin il y a de la memoire occupe

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list			*nw;

	if (!alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	nw = *alst;
	while (nw->next)
		nw = nw->next;
	nw->next = new;
}
