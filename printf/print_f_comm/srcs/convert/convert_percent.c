/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:49:51 by daoren            #+#    #+#             */
/*   Updated: 2021/08/31 18:48:03 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			convert_percent(t_printf_data *pf_var)
{
	pf_var->current_str = ft_strdup("%");
	if (pf_var->width)
		if (!convert_width(pf_var))
			return (0);
	return (1);
}
