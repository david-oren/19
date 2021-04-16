/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 14:59:29 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:09:05 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list *tmp;

	tmp = begin_list;
	while (tmp && tmp->next)
	{
		f(tmp->data);
		tmp = tmp->next;
	}
	if (tmp)
		f(tmp->data);
}