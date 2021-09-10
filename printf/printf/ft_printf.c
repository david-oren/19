

#include "ft_printf.h" 

int	ft_convspecifier(const char *str, va_list ap, t_print *opt)
{
	char	*dec;
	char	*hex_min;
	char	*hex_maj;

	dec = "0123456789";
	hex_min = "0123456789abcdef";
	hex_maj = "0123456789ABCDEF";
	if (*str == 'c')
		ft_print_char(ap, opt, 0);
	else if (*str == 's')
		ft_print_str(ap, opt, 0);
	else if (*str == 'p')
		ft_print_ptr((unsigned long long) va_arg(ap, void *), opt, 0, hex_min);
	else if (*str == 'd' || *str == 'i')
		ft_print_di((long int) va_arg(ap, int), opt, 0, dec);
	else if (*str == 'u')
		ft_print_uxx((unsigned long) va_arg(ap, unsigned int), opt, 0, dec);
	else if (*str == 'x')
		ft_print_uxx((unsigned long) va_arg(ap, unsigned int), opt, 0, hex_min);
	else if (*str == 'X')
		ft_print_uxx((unsigned long) va_arg(ap, unsigned int), opt, 0, hex_maj);
	else if (*str == '%')
		ft_print_mod(opt, 0);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	t_print	opt;
	va_list	ap;

	opt = (t_print){-1, -1, -1, -1, 0};
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			opt.res += 1;
			ft_putchar(*format);
		}
		else
		{
			opt = (t_print){-1, -1, -1, -1, opt.res};
			format++;
			format += ft_parse_flags(format, &opt, 0);
			ft_convspecifier(format, ap, &opt);
		}
		format++;
	}
	va_end(ap);
	return (opt.res);
}
