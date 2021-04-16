/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 08:27:15 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 18:59:05 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int srcsize;
	int dstsize;

	i = -1;
	srcsize = 0;
	dstsize = 0;
	while (src[++i] != '\0')
		srcsize++;
	i = -1;
	while (dest[++i] != '\0')
		dstsize++;
	i = dstsize - 1;
	while (++i < srcsize + dstsize)
		dest[i] = src[i - dstsize];
	dest[i] = '\0';
	return (dest);
}
