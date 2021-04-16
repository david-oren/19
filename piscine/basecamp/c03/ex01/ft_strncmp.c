/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:02:26 by daoren            #+#    #+#             */
/*   Updated: 2021/02/16 18:53:41 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n)
	{
		i++;
	}
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

//ex01
#include <stdio.h>
#include <string.h>
int main () {
	char s1[] = "salut les cop!ain";
	char s2[] = "salut les copain";
	printf("is        -->%i\n", ft_strncmp(s1, s2, 14));	
	printf("should be -->%i\n\n", strncmp(s1, s2, 14));
	char s3[] = "saluts les copain";
	char s4[] = "salut les copain";
	printf("is        -->%i\n", ft_strncmp(s3, s4, 8));	
	printf("should be -->%i\n\n", strncmp(s3, s4, 8));
	char s5[] = "salut les copainssssss";
	char s6[] = "salut les copain";
	printf("is        -->%i\n", ft_strncmp(s5, s6, 15));	
	printf("should be -->%i\n\n", strncmp(s5, s6, 15));
	char s7[] = "salut les copainssssss";
	char s8[] = "satlut les copain";
	printf("is        -->%i\n", ft_strncmp(s7, s8, 2));	
	printf("should be -->%i\n\n", strncmp(s7, s8, 2));
	printf("is        -->%i\n", ft_strncmp(s7, s8, 0));	
	printf("should be -->%i\n\n", strncmp(s7, s8, 0));
	return (0);
}
