/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:05:59 by daoren            #+#    #+#             */
/*   Updated: 2021/02/16 18:53:01 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (str);
	while (str[i])
	{
		k = 0;
		while (str[k + i] == to_find[j])
		{
			k++;
			j++;
			if (to_find[j] == '\0')
				return (&str[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}

//ex04
#include <stdio.h>
#include <string.h>
int main () {
	char str[] = "xavier mait vit en Belgique mais est Francais";
	char str2[] = "";
	char to_find[] = "mais";
	char to_find2[] = "";
	char to_find3[] = "maiss";
	printf("should be -->%s\n", strstr(str, to_find));
	printf("is        -->%s\n\n", ft_strstr(str, to_find));
	printf("should be -->%s\n", strstr(str, to_find2));
	printf("is        -->%s\n\n", ft_strstr(str, to_find2));
	printf("should be -->%s\n", strstr(str, to_find3));
	printf("is        -->%s\n\n", ft_strstr(str, to_find3));
	printf("should be -->%s\n", strstr(str2, to_find2));
	printf("is        -->%s\n\n", ft_strstr(str2, to_find2));
	return(0);
}