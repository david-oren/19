/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 13:39:11 by kkalinic          #+#    #+#             */
/*   Updated: 2020/09/26 14:33:11 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct.h"
#include <stdio.h>

int	main()
{
	t_num	s_dic;

	s_dic.key = "0";
	s_dic.value = "zero";

	printf("%s\n", s_dic.value);
}



