/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 10:44:40 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/27 19:33:57 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int		check_init_and_num(int init_value, char *number, t_num **dict)
{
	if (!init_value)
	{
		ft_putstr("Dict Error");
		write(1, "\n", 1);
		return (0);
	}
	else if (init_value < 0)
	{
		ft_putstr("Malloc Error");
		write(1, "\n", 1);
		return (0);
	}
	if (init_value == -1 || init_value == 0)
		free_all(dict);
	if (!check_num(number))
	{
		ft_putstr("Error");
		write(1, "\n", 1);
		return (0);
	}
	return (1);
}

int		free_bulk(t_lines *bulk, int param)
{
	if (param == 0)
		free(bulk->new);
	else if (param == 1)
	{
		free(bulk->new);
		free(bulk->num);
	}
	return (0);
}

int		pass_spaces(char *buffer, int i, int *j, int count)
{
	while (is_space(buffer[i - count + *j]))
		*j = *j + 1;
	if (buffer[i - count + *j] == ':')
		*j = *j + 1;
	else
		return (0);
	while (is_space(buffer[i - count + *j]))
		*j = *j + 1;
	return (1);
}

char	*setnum(char *buffer, int i, int *j, int count)
{
	char	*num;
	int		toobig;

	toobig = 0;
	while (is_space(buffer[i - count + *j]) && ++toobig)
		*j = *j + 1;
	while (buffer[i - count + *j] >= '0' && buffer[i - count + *j] <= '9')
		*j = *j + 1;
	if (!(num = malloc(sizeof(char) * (*j + 1 - toobig))))
		return (NULL);
	*j = 0;
	toobig = 0;
	while (is_space(buffer[i - count + *j]) && ++toobig)
		*j = *j + 1;
	while (buffer[i - count + *j] >= '0' && buffer[i - count + *j] <= '9')
	{
		num[*j - toobig] = buffer[i - count + *j];
		*j = *j + 1;
	}
	num[*j - toobig] = 0;
	return (num);
}

void	print_zero(t_num **dict)
{
	char	*zero;
	int		i;

	zero = find_in_dict(dict, "0");
	i = -1;
	while (dict[++i] && not_only_space(i, zero))
		write(1, &zero[i], 1);
}
