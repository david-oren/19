/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:43:10 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/27 18:09:51 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int		pass_non_mod(t_num **dict, char *nbr, unsigned int *index, int count)
{
	int mainvalue;

	mainvalue = 1;
	if (count % 3 == 1)
	{
		mainvalue *= check_units('0', '0', nbr[*index], dict);
		*index = *index + 1;
	}
	else if (count % 3 == 2)
	{
		mainvalue *= check_units('0', nbr[*index], nbr[*index + 1], dict);
		*index = *index + 2;
	}
	if (*index != 0)
	{
		if (count > 3)
			mainvalue *= check_suffix(count - *index + 1, dict);
	}
	return (mainvalue);
}

int		check_result(t_num **dict, char *nbr)
{
	unsigned int	count;
	unsigned int	i;
	int				mainval;

	mainval = 1;
	if (!check_non_printable(dict))
		return (-1);
	count = ft_strlen(nbr);
	i = 0;
	mainval *= pass_non_mod(dict, nbr, &i, count);
	while (i < count)
	{
		mainval *= check_units(nbr[i], nbr[i + 1], nbr[i + 2], dict);
		if ((nbr[i] != '0' || nbr[i + 1] != '0' || nbr[i + 2] != '0'))
			mainval *= check_suffix(count - i - 2, dict);
		i += 3;
	}
	return (mainval);
}

int		check_units(char c, char d, char u, t_num **dict)
{
	char	arr[3];
	int		mainval;

	mainval = 1;
	arr[0] = d;
	arr[1] = u;
	arr[2] = 0;
	if (c != '0')
	{
		mainval *= check_char_in_dict(dict, c);
		mainval *= check_in_dict(dict, "100");
	}
	mainval *= check_units2(dict, arr);
	return (mainval);
}

int		check_char_in_dict(t_num **dict, char c)
{
	int i;

	i = -1;
	while (dict[++i])
	{
		if (c == dict[i]->nbr[0] && !(dict[i]->nbr[1]))
			return (1);
	}
	return (0);
}

int		check_non_printable(t_num **dict)
{
	int i;
	int j;

	i = -1;
	while (dict[++i])
	{
		j = -1;
		while (dict[i]->text_nbr[++j])
			if (dict[i]->text_nbr[j] <= 31 && !is_space(dict[i]->text_nbr[j]))
				return (0);
	}
	return (1);
}
