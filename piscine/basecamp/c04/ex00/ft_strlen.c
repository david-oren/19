/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:30:38 by daoren            #+#    #+#             */
/*   Updated: 2021/02/17 14:29:00 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>

int ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while(str[i])
		i++;
	return (i);
}

int main (void)
{
	printf("my answer is %d\n", ft_strlen("kh_k"));
	return (0);
}