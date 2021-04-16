/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 10:51:18 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:08:53 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	if (begin_list)
		return (1 + ft_list_size(begin_list -> next));
	else
		return (0);
}

t_list  *ft_list_at(t_list *begin_list, unsigned int nbr)
{
    t_list *tmp;
    unsigned int size;
    unsigned int count;

    size = ft_list_size(begin_list);
    if (size <= nbr)
    {
        tmp = 0;
        return (tmp);
    }
	tmp = begin_list;
    count = -1;
	while (tmp)
    {
        count++;
        if (count == nbr)
            return (tmp);
        tmp = tmp->next;
    }
	return (tmp);
}