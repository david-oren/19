/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 08:29:58 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:08:44 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void    ft_list_push_back(t_list **begin_list, void *data)
{
    t_list *tmp;

    if (!begin_list || !*begin_list)
    {
        if (!begin_list)
            return ;
        *begin_list = ft_create_elem(data);
        return ;
    }
    tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
    tmp->next = ft_create_elem(data);
}