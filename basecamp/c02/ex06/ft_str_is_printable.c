/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 21:41:35 by daoren            #+#    #+#             */
/*   Updated: 2021/02/15 12:40:34 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (!((*str >= ' ' && *str <= '~')))
			return (0);
		str++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	printf("%d\n", ft_str_is_printable(argv[1]));
	return(0);
}
