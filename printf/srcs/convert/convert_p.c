/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:49:47 by daoren            #+#    #+#             */
/*   Updated: 2021/08/31 18:46:51 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	convert_p(t_printf_data *pf_var)
{
	unsigned long long int	pointer_value;
	char					*number;

	pointer_value = va_arg(pf_var->argc, unsigned long long int);
	number = ft_itoa_base_p(pointer_value, 16, "0123456789abcdef");
	pf_var->current_str = ft_strdup("0x");
	if (!(pf_var->dot && pf_var->precision == 0 && pointer_value == 0))
		pf_var->current_str = join_back(pf_var->current_str, number);
	free(number);
	if (pf_var->width)
		if (!convert_width(pf_var))
			return (0);
	return (1);
}
