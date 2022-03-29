#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	pta;
	//char	*p;
	int	i;
	int	ret;
	
	va_start(pta, fmt);
	//p = (char *)fmt;
	ret = 0;
	i = -1;
	while (fmt[++i])
	{
		if (fmt[i] == '%')
		{
			if (fmt[++i] == '%')
				ret += ft_putchar('%');
			if (fmt[i] == 'c')
				ret += ft_putchar(va_arg(pta, int));
			if (fmt[i] == 's')
				ret += ft_putstr(va_arg(pta, char *));
			if (fmt[i] == 'p')
				ret += print_address_hex(va_arg(pta, void *));	
			if (fmt[i] == 'd')
				ft_putnbr(va_arg(pta, int), &ret);
			if (fmt[i] == 'i')
				ft_putnbr(va_arg(pta, int), &ret);
			if (fmt[i] == 'u')
				ft_u_putnbr(va_arg(pta, int), &ret);
			if (fmt[i] == 'x')
				ft_print_hex(va_arg(pta, unsigned int), 'x', &ret);
			if (fmt[i] == 'X')
				ft_print_hex(va_arg(pta, unsigned int), 'X',&ret);
		}
		else
			ret += ft_putchar(fmt[i]);
	}
	return (ret);
}
