/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:42:18 by daoren            #+#    #+#             */
/*   Updated: 2021/08/31 18:52:14 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/ft_printf.h"

static void	check_negative(t_printf_data *pf_var)
{
	if (pf_var->width < 0)
	{
		pf_var->width = 0 - pf_var->width;
		if (!pf_var->minus)
			pf_var->minus = 1;
		pf_var->zero = 0;
	}
	if (pf_var->precision < 0)
	{
		pf_var->precision = -1;
		pf_var->dot = 0;
	}
	if (pf_var->dot && pf_var->zero && pf_var->current_char != '%')
		pf_var->zero = 0;
}

static int	fill_struct(t_printf_data *pf_var, const char *str)
{
	int len;
	int i;

	len = -1;
	i = 0;
	if (str[0] == '-')
		pf_var->minus = 1;
	pf_var->width = ft_pf_atoi(pf_var, &str[i], &i);
	if (str[0] == '0')
		pf_var->zero = 1;
	while (str[++len] && is_in_str("0123456789-.*", str[len]))
		;
	while (str[i] && is_in_str("0123456789-.*", str[i]))
	{
		if (str[i] == '.')
		{
			pf_var->dot = 1;
			pf_var->precision = ft_pf_atoi(pf_var, &str[i + 1], &i);
		}
		i++;
	}
	return (len);
}

static int	ft_printf_loop(t_printf_data *pf_var, const char *str)
{
	int print_len;
	int i;

	i = -1;
	print_len = 0;
	pf_var->current_str = NULL;
	while (str[++i])
	{
		if (str[i] != '%')
			write_and_add(&print_len, str[i]);
		else
		{
			i++;
			init_struct(pf_var);
			i += fill_struct(pf_var, &str[i]);
			if (!is_in_str("cspdiuxX%", str[i]))
				return (-1);
			pf_var->current_char = str[i];
			check_negative(pf_var);
			if (!ft_stringify(pf_var))
				return (-1);
			write_str_and_add(pf_var, &print_len);
		}
	}
	return (print_len);
}

int			ft_printf(const char *format, ...)
{
	int				print_len;
	t_printf_data	*pf_var;

	if (!format || !(pf_var = malloc(sizeof(t_printf_data))))
		return (-1);
	va_start(pf_var->argc, format);
	print_len = ft_printf_loop(pf_var, format);
	va_end(pf_var->argc);
	free(pf_var->current_str);
	free(pf_var);
	return (print_len);
}
