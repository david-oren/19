/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:02:02 by daoren            #+#    #+#             */
/*   Updated: 2021/02/16 18:53:54 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] != '\0') && (s2 != '\0') && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

//ex00
#include <stdio.h>
int main () {
	char s1[] = "salut les copain";
	char s2[] = "salut les copain";
	printf("is        -->");
	printf("%i\n", ft_strcmp(s1, s2));	
	printf("should be -->O\n");
	char s3[] = "salut les copain";
	char s4[] = "saluts les copain";
	printf("is        -->");
	printf("%i\n", ft_strcmp(s3, s4));	
	printf("should be -->-83\n");
	char s5[] = "salut les copains";
	char s6[] = "salut les copain";
	printf("is        -->");
	printf("%i\n", ft_strcmp(s5, s6));	
	printf("should be -->115\n");
	return (0);
}