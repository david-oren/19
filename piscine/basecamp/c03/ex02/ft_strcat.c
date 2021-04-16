/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:02:44 by daoren            #+#    #+#             */
/*   Updated: 2021/02/16 18:53:28 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

//ex02
#include <stdio.h>
int main () {
	char src[] = "xavier";
	char dest[] = "auffray";
	printf("is        -->");
	printf("%s\n", ft_strcat(dest, src));	
	printf("should be -->auffrayxavier");
	return(0);
}