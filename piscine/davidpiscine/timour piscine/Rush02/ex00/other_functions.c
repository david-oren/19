/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:43:14 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/27 14:22:02 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int		is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

void	ft_puttextnumber(char *str)
{
	int i;
	int space;

	i = -1;
	space = 0;
	while (str[++i] && not_only_space(i, str))
	{
		if (is_space(str[i]))
		{
			if (!space)
			{
				space = 1;
				write(1, " ", 1);
			}
		}
		else
		{
			write(1, &str[i], 1);
			space = 0;
		}
	}
}

int		check_in_dict(t_num **dict, char *str)
{
	int i;

	i = -1;
	while (dict[++i])
	{
		if (!ft_strcmp(str, dict[i]->nbr))
			return (1);
	}
	return (0);
}

int		check_units2(t_num **dict, char *arr)
{
	int mainval;

	mainval = 1;
	if (arr[0] < '2')
	{
		if (arr[0] < '1')
		{
			if (arr[1] != '0')
				mainval *= check_char_in_dict(dict, arr[1]);
		}
		else
			mainval *= check_in_dict(dict, arr);
	}
	else
	{
		arr[1] = '0';
		mainval *= check_in_dict(dict, arr);
		if (arr[1] != '0')
		{
			mainval *= check_char_in_dict(dict, arr[1]);
		}
	}
	return (mainval);
}

void	print_units2(t_num **dict, char *arr, char u)
{
	if (arr[0] < '2')
	{
		if (arr[0] < '1')
		{
			if (arr[1] != '0')
				ft_puttextnumber(find_char_in_dict(dict, arr[1]));
		}
		else
			ft_puttextnumber(find_in_dict(dict, arr));
	}
	else
	{
		arr[1] = '0';
		ft_puttextnumber(find_in_dict(dict, arr));
		if (arr[0] != '0')
		{
			ft_putstr(" ");
			ft_puttextnumber(find_char_in_dict(dict, u));
		}
	}
}
