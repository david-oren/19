/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_print_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 08:31:51 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:09:25 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

int	ft_list_size2(t_list *begin_list)
{
	if (begin_list)
		return (1 + ft_list_size2(begin_list -> next));
	else
		return (0);
}

void print_node(t_list *begin_list)
{
    t_list *tmp;

    tmp = begin_list;
    printf("Cette structure comporte < %i > elements et < %i > nodes\n", ft_list_size2(begin_list), ft_list_size2(begin_list) - 1);
	while (tmp)
    {
        if (tmp->next)
            printf("%s -> ", tmp->data);
        else
            printf("%s\n", tmp->data);
        tmp = tmp->next;
    }
}