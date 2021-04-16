/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:03:31 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:09:14 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *tmp;

	tmp = begin_list;
	while (tmp->next && tmp)
	{
		if (!cmp(tmp->data, data_ref))
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp && !cmp(tmp->data, data_ref))
		return (tmp);
	return (NULL);
}
