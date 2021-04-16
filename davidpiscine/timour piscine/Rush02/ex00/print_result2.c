/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:05:40 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/27 18:05:01 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	write_suffix(unsigned int count, t_num **dict, int index, char *num)
{
	char			*suff;
	unsigned int	i;

	(void)num;
	(void)index;
	i = -1;
	if (count == 1)
		return ;
	if (!(suff = malloc(sizeof(char) * (count + 1))))
		return ;
	while (++i < count)
		suff[i] = '0';
	suff[0] = '1';
	suff[count] = 0;
	ft_puttextnumber(find_in_dict(dict, suff));
	free(suff);
}

int		test_if_end(int index, char *num)
{
	unsigned int i;

	i = (unsigned int)index + 1;
	while (num[++i])
		if (num[i] != '0')
			return (1);
	return (0);
}
