/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:29:41 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 22:17:21 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "stdlib.h"

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