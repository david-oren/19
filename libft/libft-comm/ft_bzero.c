/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:14:16 by daoren            #+#    #+#             */
/*   Updated: 2021/03/15 13:26:53 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Initialiser une string et faire en sorte qu'il y ait 0 octets dans chaque case mémoire.
// La  fonction  bzero() met à 0 les n premiers octets du bloc pointé par s (octets contenant« \0 »).
// On ne sait pas à l'avance si s va être composé de char ou d'int donc on met void

// ft_memset va retourner la string avec des 0 sur les n premiers octets de s, d'où le (s, 0, n)

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
