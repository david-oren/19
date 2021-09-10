

#include "ft_printf.h"

int	ft_reached_convspecifier(const char *str)
{
	char	*conversion;

	conversion = "cspdiuxX%";
	while (str && *str)
	{
		while (*conversion)
		{
			if (*str == *conversion)
				return (1);
			conversion++;
		}
		str++;
	}
	return (0);
}

int	ft_parse_flags(const char *str, t_print *opt, int i)
{
	while (!ft_reached_convspecifier(str + i))
	{
		if (*(str + i) == '0')
			(*opt).flag_zero = 1;
		else if (*(str + i) == '-')
			(*opt).flag_minus = 1;
		else if (ft_isdigit(*(str + i)) && (*opt).prec == -1)
		{
			(*opt).width = ft_atoi(str + i);
			i += ft_int_len((*opt).width) - 1;
		}
		else if (*(str + i) == '.')
		{
			(*opt).prec = 0;
			if (ft_isdigit(*(str + i + 1)))
			{
				(*opt).prec = ft_atoi(str + i + 1);
				i += ft_int_len((*opt).prec);
			}	
		}
		i++;
	}
	if ((*opt).flag_minus == 1 && (*opt).flag_zero == 1)
		(*opt).flag_zero = -1;
	return (i);
}
