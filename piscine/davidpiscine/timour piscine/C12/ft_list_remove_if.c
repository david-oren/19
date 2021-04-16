/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:18:21 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:09:22 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void 	free_first(t_list **begin_list, void(*free_fct)(void *))
{
	t_list *tosup;

	tosup = *begin_list;
	if ((*begin_list)->next)
		*begin_list = (*begin_list)->next;
	else
		*begin_list = NULL;
	free_fct(tosup->data);
	free(tosup);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void(*free_fct)(void *))
{
	t_list *tmp;
	t_list *tosup;
	int		first;

	tmp = *begin_list;
	first = 0;
	if (tmp && !cmp(tmp->data, data_ref))
		first = 1;
	while (tmp && tmp->next)
	{
		if (!cmp(tmp->next->data, data_ref))
		{
			tosup = tmp->next;
			free_fct(tosup->data);
			if (tosup->next)
				tmp->next = tosup->next;
			else
				tmp->next = NULL;
			free(tosup);
		}
		tmp = tmp->next;
	}
	if (first)
		free_first(begin_list, free_fct);
}