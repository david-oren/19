/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:35:17 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 18:47:25 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_string(char *pointeur, char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		pointeur[i] = str[i];
	}
}

void	print_list(int *arr)
{
	char	nub[10];
	int		i;

	ft_string(nub, "0123456789");
	i = -1;
	while (++i < 2)
	{
		write(1, &nub[arr[i] / 10], 1);
		write(1, &nub[arr[i] % 10], 1);
		if (i == 0)
			write(1, " ", 1);
	}
	if (arr[0] != 98)
		write(1, ", ", 2);
}

void	new_step(int *arr)
{
	if (arr[1] < 99)
		arr[1]++;
	else if (arr[0] < 99)
	{
		arr[0]++;
		arr[1] = arr[0] + 1;
	}
	print_list(arr);
}

void	ft_print_comb2(void)
{
	int main_array[2];

	main_array[0] = 0;
	main_array[1] = 0;
	while (main_array[0] != 98)
	{
		new_step(main_array);
	}
}
