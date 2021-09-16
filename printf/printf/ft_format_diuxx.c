/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_diuxx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 03:29:13 by daoren            #+#    #+#             */
/*   Updated: 2021/09/16 03:29:16 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_zero(t_print *opt, int char_printed)
{
	if ((*opt).width >= 1)
		char_printed += ft_pad_space(0, (*opt).width);
	(*opt).res += char_printed;
	return (1);
}

int	ft_print_flags(t_print *opt, int len, long long nbr, char *base)
{
	int	i;
	int	char_printed;

	i = ft_isnegative(nbr);
	char_printed = 0;
	if (nbr < 0)
		write(1, "-", 1);
	if (nbr < 0)
		nbr *= -1;
	if ((*opt).flag_zero == 1 && (*opt).prec == -1)
	{
		char_printed += ft_pad_zero(len, (*opt).width);
		ft_putnbr_base(nbr, base);
	}
	else if ((*opt).flag_minus == 1)
	{
		if ((*opt).prec > len)
			char_printed += ft_pad_zero(len - i, (*opt).prec);
		ft_putnbr_base(nbr, base);
		if ((*opt).prec > len)
			char_printed += ft_pad_space((*opt).prec + i, (*opt).width);
		else
			char_printed += ft_pad_space(len, (*opt).width);
	}
	return (char_printed);
}

int	ft_print_no_flags(t_print *opt, int len, long long nbr, char *base)
{
	int	i;
	int	char_printed;

	i = ft_isnegative(nbr);
	char_printed = 0;
	if ((*opt).prec < len)
	{
		char_printed += ft_pad_space(len, (*opt).width);
		if (nbr < 0)
			write(1, "-", 1);
	}
	else
	{
		char_printed += ft_pad_space((*opt).prec + i, (*opt).width);
		if (nbr < 0)
			write(1, "-", 1);
		char_printed += ft_pad_zero(len - i, (*opt).prec);
	}
	if (nbr < 0)
		nbr *= -1;
	ft_putnbr_base(nbr, base);
	return (char_printed);
}

int	ft_print_di(long int nbr, t_print *opt, int char_printed, char *base)
{
	int	i;
	int	len;

	i = ft_isnegative(nbr);
	len = ft_int_len(nbr);
	if ((*opt).prec == 0 && nbr == 0)
		return (ft_print_zero(opt, char_printed));
	if ((*opt).width > (*opt).prec && (*opt).width > len)
	{
		if ((*opt).flag_minus == 1
			|| ((*opt).flag_zero == 1 && (*opt).prec == -1))
			char_printed += ft_print_flags(opt, len, nbr, base);
		else
			char_printed += ft_print_no_flags(opt, len, nbr, base);
		return ((*opt).res += char_printed + len);
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}	
	if ((*opt).prec >= len)
		char_printed += ft_pad_zero(len - i, (*opt).prec);
	ft_putnbr_base(nbr, base);
	return ((*opt).res += char_printed + len);
}

int	ft_print_uxx(unsigned long nbr, t_print *opt, int char_printed, char *base)
{
	int		len;

	len = ft_long_len(nbr, base);
	if ((*opt).prec == 0 && nbr == 0)
		return (ft_print_zero(opt, char_printed));
	if ((*opt).width > (*opt).prec && (*opt).width > len)
	{
		if ((*opt).flag_minus == 1
			|| ((*opt).flag_zero == 1 && (*opt).prec == -1))
			char_printed += ft_print_flags(opt, len, nbr, base);
		else
			char_printed += ft_print_no_flags(opt, len, nbr, base);
	}
	else
	{
		if ((*opt).prec > len)
			char_printed += ft_pad_zero(len, (*opt).prec);
		ft_putnbr_base(nbr, base);
	}
	(*opt).res += char_printed + len;
	return (1);
}
