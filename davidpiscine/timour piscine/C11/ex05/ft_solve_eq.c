/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_eq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 08:04:44 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:08:00 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_op.h"

void (*g_make_op[5])(int, int) = {ft_add, ft_sub, ft_mul, ft_div, ft_mod};

int		ft_strlen(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int		ret_ope(char *op)
{
	if (ft_strlen(op) != 1)
		return (-1);
	else if (op[0] == '+')
		return (0);
	else if (op[0] == '-')
		return (1);
	else if (op[0] == '*')
		return (2);
	else if (op[0] == '/')
		return (3);
	else if (op[0] == '%')
		return (4);
	else
		return (-1);
}

void	ft_solve_eq(char *num1, char *operation, char *num2)
{
	int nbr1;
	int nbr2;
	int op;

	nbr1 = ft_atoi(num1);
	nbr2 = ft_atoi(num2);
	op = ret_ope(operation);
	if (op < 0)
	{
		ft_putnbr(0);
		ft_putstr("\n");
	}
	else
		g_make_op[op](nbr1, nbr2);
}
