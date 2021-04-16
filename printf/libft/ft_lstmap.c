/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:45:57 by daoren            #+#    #+#             */
/*   Updated: 2021/04/14 17:46:55 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freeall(t_list *lst)
{
	t_list	*tmp;

	tmp = NULL;
	ft_lstnew(tmp->content);
	while (lst)
	{
		tmp = lst;
		free(lst->content);
		free(lst);
		lst = tmp->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*ptr;

	if (!lst)
		return (NULL);
	if (!f)
		return (NULL);
	ptr = NULL;
	while (lst)
	{
		list = ft_lstnew(f(lst->content));
		if (!list)
		{
			if (del)
				ft_lstclear(&list, del);
			else
				ft_freeall(list);
			return (NULL);
		}
		ft_lstadd_back(&ptr, list);
		lst = lst->next;
	}
	return (ptr);
}
