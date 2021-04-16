/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verificator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:39:17 by cjulienn          #+#    #+#             */
/*   Updated: 2021/02/22 11:35:50 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lib.h"

int g_return_error = 0;

void	ft_clean_input(char src[], char copy[])		va prendre l input et va retourner uine copie sans 
{													les espace et on en a besoin pour la fct checkmate					
	int i;
	int j;
	int lg;

	i = 0;
	j = 0;
	lg = ft_strlen(src);
	while (i < lg)
	{
		if (src[i] != ' ')
		{
			copy[j] = src[i];
			j++;
		}
		i++;
	}
	copy[j] = '\0';
}
