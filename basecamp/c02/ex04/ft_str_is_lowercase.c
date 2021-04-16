/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 21:41:40 by daoren            #+#    #+#             */
/*   Updated: 2021/02/15 12:14:09 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_str_is_lowercase(char *str)
{
	while (*str != '\0')
	{
		if (!((*str >= 'a' && *str <= 'z')))
			return (0);
		str++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	printf("%d\n", ft_str_is_lowercase(argv[1]));
	return(0);
}
