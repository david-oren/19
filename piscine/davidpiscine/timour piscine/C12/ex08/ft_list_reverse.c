/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:23:25 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:09:03 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*prec;
	t_list	*curr;

	prec = 0;
	while (*begin_list)
	{
		curr = (*begin_list)->next;
		(*begin_list)->next = prec;
		prec = *begin_list;
		*begin_list = curr;
	}
	*begin_list = prec;
}