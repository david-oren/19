/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 10:44:56 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:08:50 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void    ft_list_clear(t_list *begin_list, void(*free_fct)(void *))
{
    if (!begin_list)
        return ;
    ft_list_clear(begin_list->next, free_fct);
    if (free_fct)
        free_fct(begin_list->data);
    free(begin_list);
}