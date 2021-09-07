/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:49:42 by daoren            #+#    #+#             */
/*   Updated: 2021/08/31 18:46:23 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	edit_di_values(t_printf_data *pf_var)
{
	if (pf_var->zero && !pf_var->dot && pf_var->width)
	{
		pf_var->precision = pf_var->width;
		pf_var->width = 0;
		pf_var->dot = 1;
		pf_var->zero = 0;
	}
}

static int	convert_di_precision_neg(t_printf_data *pf_var)
{
	char		*space_string;
	const int	to_r = pf_var->zero && !pf_var->dot;
	int			remaining_length;
	char		*new_str;

	edit_di_values(pf_var);
	remaining_length = pf_var->precision -
		ft_strlen(pf_var->current_str) + 1 - to_r;
	new_str = ft_strdup(&(pf_var->current_str)[1]);
	free(pf_var->current_str);
	if (!(space_string = string_with_length('0',
		remaining_length > 0 ? remaining_length : 0)))
		return (free_and_return(space_string, 0));
	if (!(new_str = join_front(new_str, space_string)))
		return (free_and_return(space_string, 0));
	if (!(new_str = join_front(new_str, "-")))
		return (free_and_return(space_string, 0));
	pf_var->current_str = ft_strdup(new_str);
	free(new_str);
	return (free_and_return(space_string, 1));
}

static int	convert_di_precision(t_printf_data *pf_var)
{
	char	*space_string;
	int		remaining_length;

	remaining_length = pf_var->precision - ft_strlen(pf_var->current_str);
	if (!(space_string = string_with_length('0',
		remaining_length > 0 ? remaining_length : 0)))
		return (free_and_return(space_string, 0));
	else if (!(pf_var->current_str =
		join_front(pf_var->current_str, space_string)))
		return (free_and_return(space_string, 0));
	return (free_and_return(space_string, 1));
}

int			deal_di_flags(t_printf_data *pf_var, int nb)
{
	if (pf_var->dot || pf_var->zero)
	{
		if (nb == 0 && pf_var->precision != -1 && pf_var->dot)
		{
			free(pf_var->current_str);
			pf_var->current_str = string_with_length('0', pf_var->precision);
		}
		else if (nb >= 0)
		{
			if (!(convert_di_precision(pf_var)))
				return (0);
		}
		else if (nb < 0)
			if (!(convert_di_precision_neg(pf_var)))
				return (0);
	}
	if (pf_var->width)
		if (!convert_width(pf_var))
			return (0);
	return (1);
}

int			convert_di(t_printf_data *pf_var)
{
	int nb;

	nb = va_arg(pf_var->argc, int);
	pf_var->current_str = ft_itoa_base(nb, 10, "0123456789");
	if (!(pf_var->current_str))
		return (0);
	return (deal_di_flags(pf_var, nb));
}
