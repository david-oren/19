/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:28:03 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/27 10:06:05 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	free_all(t_num **dict)
{
	int i;

	i = -1;
	while (dict[++i])
	{
		free(dict[i]->nbr);
		free(dict[i]->text_nbr);
		free(dict[i]);
	}
	free(dict);
}
