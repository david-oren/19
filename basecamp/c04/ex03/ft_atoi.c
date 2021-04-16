/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:29:57 by daoren            #+#    #+#             */
/*   Updated: 2021/02/20 23:45:47 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(char *str)
{
	int a;
	int b;

	a = 0;
	b = 1;
	while((*str >= 9 && *str <= 13) || (*str == ' ') || (*str == '	'))
		str++;
	while(*str == '+' || *str == '-')
	{
		if(*str == '-')
			b = b * -1;
		str++;
	}
	while(*str >= '0' && *str <= '9')
	{
		a = a * 10 + (*str - '0');
		str++;
	}
	return (a * b);
}

#include <stdio.h>


#include <stdlib.h> 
#include <stdio.h> // kill after tests

int main(void) // kill after tests
{
    char a[] = "+++ --543- - 666--- ++  +12345abcd303";
    char b[] = " ---+--+1234ab567";
    char c[] = " ----- ++++ aa 777 +-- 1234-";
    char d[] = "1234 ----";
    char e[] = "";
    char f[] = "a12a34";
    printf("%d\n\n", ft_atoi(a));
    printf("%d\n\n", ft_atoi(b));
    printf("%d\n\n", ft_atoi(c));
    printf("%d\n\n", ft_atoi(d));
    printf("%d\n\n", ft_atoi(e));
    printf("%d\n\n", ft_atoi(f));
    return 0;
}