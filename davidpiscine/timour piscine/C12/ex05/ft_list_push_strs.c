/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 10:29:12 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:08:47 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *first;

	if ((first = ft_create_elem(data)))
	{
		if (*begin_list)
			first->next = *begin_list;
		*begin_list = first;
	}
}

t_list *ft_list_push_strs(int size, char **strs)
{
    int i;
    t_list *begin_list;

    i = -1;
    begin_list = 0;
    while (++i < size)
    {
        ft_list_push_front(&begin_list, strs[i]);
    }
    return (begin_list);
}