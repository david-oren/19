#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct	s_printf
{
	va_list	ap;
	int		i;
	int		len;
	int		width;
	int		precision;
	int		precision_width;
	int		precision_parsing;
	int		ret;
}				t_printf;

void	reset_struct(t_printf *tab)
{
	tab->len = 0;
	tab->width = 0;
	tab->precision = 0;
	tab->precision_width = 0;
	tab->precision_parsing = 0;
}

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_l(char *s, int len)
{
	write(1, s, len);
}

int		ft_intlen_base(intmax_t nb, char *base)
{
	int		len;
	int		base_len;

	len = 1;
	base_len = ft_strlen(base);
	if (nb < 0)
		nb = -nb;
	while (nb >= base_len)
	{
		nb = nb / base_len;
		len++;
	}
	return (len);
}

void	ft_putnbr_base(intmax_t nb, char *base)
{
	int		base_len;

	base_len = ft_strlen(base);
	if (nb < 0)
		nb = -nb;
	if (nb >= base_len)
		ft_putnbr_base(nb / base_len, base);
	ft_putchar(base[nb % base_len]);
}

int		ft_atoi(char *str, t_printf *tab)
{
	int		atoi;

	atoi = 0;
	while (str[tab->i] >= '0' && str[tab->i] <= '9')
	{
		atoi = atoi * 10 + str[tab->i] - 48;
		tab->i++;
	}
	tab->i--;
	return (atoi);
}

int		is_conv(char c)
{
	return (c == 's' || c == 'x' || c == 'd');
}

void	print_spaces(t_printf *tab, int len)
{
	int		i;

	i = 0;
	if (len < 0)
		return ;
	while (i < len)
	{
		ft_putchar(' ');
		i++;
	}
	tab->ret += len;
}

void	print_zero(t_printf *tab, int len)
{
	int		i;

	i = 0;
	if (len < 0)
		return ;
	while (i < len)
	{
		ft_putchar('0');
		i++;
	}
	tab->ret += len;
}

void	convert_str(t_printf *tab)
{
	char *str;

	str = va_arg(tab->ap, char *);
	if (!str)
		str = "(null)";
	tab->len = ft_strlen(str);
	if (tab->precision && tab->precision_width < tab->len)
		tab->len = tab->precision_width;
	print_spaces(tab, tab->width - tab->len);
	ft_putstr_l(str, tab->len);
	tab->ret += tab->len;
}

void	convert_int(t_printf *tab)
{
	intmax_t 	nb;
	int			sp;

	sp = 0;
	nb = va_arg(tab->ap, int);
	tab->len = ft_intlen_base(nb, "0123456789");
	if (nb == 0)
		tab->len = 0;
	if (tab->precision && tab->precision_width > tab->len)
	   sp = tab->precision_width - tab->len;
	if (nb < 0)
		tab->len += 1;
	print_spaces(tab, tab->width - (sp + tab->len));
	if (nb < 0)
		ft_putchar('-');
	print_zero(tab, sp);
	if (tab->precision && nb == 0)
		return;
	ft_putnbr_base(nb, "0123456789");
	tab->ret += tab->len;
}

void	convert_hex(t_printf *tab)
{
	intmax_t 	nb;
	int			sp;

	sp = 0;
	nb = va_arg(tab->ap, unsigned int);
	tab->len = ft_intlen_base(nb, "0123456789abcdef");
	if (tab->precision && tab->precision_width > tab->len)
	   sp = tab->precision_width - tab->len;
	print_spaces(tab, tab->width - (sp + tab->len));
	print_zero(tab, sp);
	if (tab->precision && tab->precision_width == 0 &&  nb == 0)
		return;
	ft_putnbr_base(nb, "0123456789abcdef");
	tab->ret += tab->len;
}

void	parse(char *str, t_printf *tab)
{
	tab->i++;
	reset_struct(tab);
	while (!is_conv(str[tab->i]))
	{
		if (str[tab->i] >= '0' && str[tab->i] <= '9')
		{
			if (tab->precision_parsing)
				tab->precision_width = ft_atoi(str, tab);
			else
				tab->width = ft_atoi(str, tab);
		}
		tab->precision_parsing = 0;
		if (str[tab->i] == '.')
		{
			tab->precision = 1;
			tab->precision_parsing = 1;
		}
		tab->i++;
	}
	str[tab->i] == 's' ? convert_str(tab) : 0;
	str[tab->i] == 'd' ? convert_int(tab) : 0;
	str[tab->i] == 'x' ? convert_hex(tab) : 0;
}

int		ft_printf(const char *str, ...)
{
	t_printf tab;

	tab.i = 0;
	tab.ret = 0;
	va_start(tab.ap, str);
	while (str[tab.i])
	{
		if (str[tab.i] == '%')
			parse((char*)str, &tab);
		else
		{
			ft_putchar(str[tab.i]);
			tab.ret++;
		}
		tab.i++;
	}
	va_end(tab.ap);
	return (tab.ret);
}
