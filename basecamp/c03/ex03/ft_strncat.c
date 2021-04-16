/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:05:41 by daoren            #+#    #+#             */
/*   Updated: 2021/02/16 18:53:15 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

//ex03
#include <stdio.h>
#include <string.h>
int main () {
	char src[] = "xavier";
	char dest[] = "auffray";
	printf("is        -->%s\n", ft_strncat(dest, src, 10));
	char src2[] = "xavier";
	char dest2[] = "auffray";	
	printf("should be -->%s\n\n", strncat(dest2, src2, 10));
	char src3[] = "";
	char dest3[] = "auffray";
	printf("is        -->%s\n", ft_strncat(dest3, src3, 0));
	char src4[] = "";
	char dest4[] = "auffray";	
	printf("should be -->%s\n\n", strncat(dest4, src4, 0));
	char src5[] = "xavier";
	char dest5[] = "";
	printf("is        -->%s\n", ft_strncat(dest5, src5, 10));
	char src6[] = "xavier";
	char dest6[] = "";	
	printf("should be -->%s\n\n", strncat(dest6, src6, 10));
	return(0);
}