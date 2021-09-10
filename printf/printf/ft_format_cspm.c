
#include "ft_printf.h"

int	ft_print_char(va_list ap, t_print *opt, int char_printed)
{
	char	c;

	char_printed = 1;
	c = (unsigned char)va_arg(ap, int);
	if ((*opt).width != -1)
	{
		if ((*opt).flag_minus == -1)
		{
			char_printed += ft_pad_space(1, (*opt).width);
			write(1, &c, 1);
		}
		else
		{
			write(1, &c, 1);
			char_printed += ft_pad_space(1, (*opt).width);
		}
	}
	else
		write(1, &c, 1);
	(*opt).res += char_printed;
	return (1);
}

int	ft_print_str(va_list ap, t_print *opt, int char_printed)
{
	int		min;
	char	*str;

	str = (char *)va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	min = ft_min(ft_strlen(str), (*opt).prec);
	if ((*opt).width > min)
	{
		if ((*opt).flag_minus == 1)
		{
			write(1, str, min);
			char_printed += ft_pad_space(min, (*opt).width);
		}
		else
		{
			char_printed += ft_pad_space(min, (*opt).width);
			write(1, str, min);
		}
	}
	else
		write(1, str, min);
	(*opt).res += char_printed + min;
	return (1);
}

int	ft_print_nil(t_print *opt, int char_printed)
{
	char	*str;

	if ((*opt).prec == 0)
		str = "0x";
	else
		str = "0x0";
	if ((*opt).flag_minus != -1)
	{
		char_printed += write(1, str, ft_strlen(str));
		char_printed += ft_pad_space(ft_strlen(str), (*opt).width);
	}
	else
	{
		char_printed += ft_pad_space(ft_strlen(str), (*opt).width);
		char_printed += write(1, str, ft_strlen(str));
	}
	return (char_printed);
}

int	ft_print_ptr(unsigned long long nbr, t_print *opt, int c, char *base)
{
	int		len;
	char	*str;

	len = ft_long_len(nbr, base);
	str = "0x";
	if (nbr == 0)
		c += ft_print_nil(opt, c);
	else if ((*opt).flag_minus != -1)
	{
		c += write(1, str, 2);
		ft_putnbr_base(nbr, base);
		c += ft_pad_space(len + ft_strlen(str), (*opt).width);
		c += len;
	}
	else
	{
		c += ft_pad_space(len + ft_strlen(str), (*opt).width);
		c += write(1, str, 2);
		ft_putnbr_base(nbr, base);
		c += len;
	}
	(*opt).res += c;
	return (1);
}

int	ft_print_mod(t_print *opt, int char_printed)
{
	char	c;

	c = '%';
	if ((*opt).flag_minus == 1)
	{
		char_printed += write(1, &c, 1);
		if ((*opt).width)
			char_printed += ft_pad_space(1, (*opt).width);
	}
	else if ((*opt).flag_zero == 1)
	{
		if ((*opt).width)
			char_printed += ft_pad_zero(1, (*opt).width);
		char_printed += write(1, &c, 1);
	}
	else
	{
		if ((*opt).width)
			char_printed += ft_pad_space(1, (*opt).width);
		char_printed += write(1, &c, 1);
	}
	(*opt).res += char_printed;
	return (1);
}
