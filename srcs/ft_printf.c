#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	pta;
	char	*p;
	int	ret;
	
	va_start(pta, fmt);
	p = (char *)fmt;
	ret = 0;
	while (*p)
	{
		if (*p == '%')
		{
			++p;
			if (*p == '%')
				ret += ft_putchar('%');
			if (*p == 'c')
				ret += ft_putchar(va_arg(pta, int));
			if (*p == 's')
				ret += ft_putstr(va_arg(pta, char *));
			if (*p == 'p')
				ret += print_address_hex(va_arg(pta, void *));	
			if (*p == 'd')
				ft_putnbr(va_arg(pta, int), &ret);
			if (*p == 'i')
				ft_putnbr(va_arg(pta, int), &ret);
			if (*p == 'u')
				ft_u_putnbr(va_arg(pta, int), &ret);
			if (*p == 'x')
				ft_print_hex(va_arg(pta, unsigned int), 'x', &ret);
			if (*p == 'X')
				ft_print_hex(va_arg(pta, unsigned int), 'X',&ret);
		}
		else
			ret += ft_putchar(*p);
		++p;	
	}
	return (ret);
}
