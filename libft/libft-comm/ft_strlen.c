/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:55:04 by daoren            #+#    #+#             */
/*   Updated: 2021/04/15 17:54:01 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)	// prototypage avec size_t car size_t correspond à un unsigned int avec au moins 16 bits, il ne peut pas contenir de valeur négative. 
{
	unsigned int	i;

	i = 0;
	while (s && s[i])		// rajouter s && pour proteger son strlen si on envoi NULL
		i++;
	return (i);
}
