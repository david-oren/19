/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:34:52 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 18:47:22 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_arr(int *arr)
{
	write(1, &arr[0], 1);
	write(1, &arr[1], 1);
	write(1, &arr[2], 1);
	if (arr[0] != '7')
		write(1, ", ", 2);
}

void	new_step(int *arr)
{
	if (arr[2] < '9')
		arr[2]++;
	else if (arr[1] < '8')
	{
		arr[1]++;
		arr[2] = arr[1] + 1;
	}
	else if (arr[0] < '7')
	{
		arr[0]++;
		arr[1] = arr[0] + 1;
		arr[2] = arr[1] + 1;
	}
	print_arr(arr);
}

void	ft_print_comb(void)
{
	int main_array[3];
	int i;

	i = -1;
	main_array[0] = '0';
	main_array[1] = '1';
	main_array[2] = '2';
	print_arr(main_array);
	while (main_array[0] != '7')
	{
		new_step(main_array);
	}
}
