/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 12:22:28 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/27 18:20:26 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	print_result(t_num **dict, char *nbr)
{
	unsigned int count;
	unsigned int i;

	count = ft_strlen(nbr);
	i = 0;
	pass_not_mod_print(dict, nbr, &i, count);
	while (i < count)
	{
		print_units(nbr[i], nbr[i + 1], nbr[i + 2], dict);
		if ((nbr[i] != '0' || nbr[i + 1] != '0' || nbr[i + 2] != '0'))
		{
			if (i != count - 3)
				write(1, " ", 1);
			write_suffix(count - i - 2, dict, i, nbr);
			if (i + 3 < count && test_if_end(i + 3, nbr))
				write(1, " ", 1);
		}
		i += 3;
	}
}

void	pass_not_mod_print(t_num **dict, char *nbr, unsigned int *i,
		unsigned int count)
{
	if (count % 3 == 1)
	{
		print_units('0', '0', nbr[*i], dict);
		*i = *i + 1;
	}
	else if (count % 3 == 2)
	{
		print_units('0', nbr[*i], nbr[*i + 1], dict);
		*i = *i + 2;
	}
	if (*i != 0 && count % 3)
	{
		if (count > 3)
			write(1, " ", 1);
		write_suffix(count - *i + 1, dict, *i, nbr);
		if (test_if_end(*i, nbr) && count > 3)
			write(1, " ", 1);
	}
}

void	print_units(char c, char d, char u, t_num **dict)
{
	char	arr[3];

	arr[0] = d;
	arr[1] = u;
	arr[2] = 0;
	if (c != '0')
	{
		ft_puttextnumber(find_char_in_dict(dict, c));
		ft_putstr(" ");
		ft_puttextnumber(find_in_dict(dict, "100"));
	}
	if ((d != '0' || u != '0') && c != '0')
		ft_putstr(" ");
	print_units2(dict, arr, u);
}

char	*find_char_in_dict(t_num **dict, char c)
{
	int i;

	i = -1;
	while (dict[++i])
	{
		if (c == dict[i]->nbr[0] && !(dict[i]->nbr[1]))
			return (dict[i]->text_nbr);
	}
	return ("NULL");
}

char	*find_in_dict(t_num **dict, char *str)
{
	int i;

	i = -1;
	while (dict[++i])
	{
		if (!ft_strcmp(str, dict[i]->nbr))
			return (dict[i]->text_nbr);
	}
	return ("NULL");
}
