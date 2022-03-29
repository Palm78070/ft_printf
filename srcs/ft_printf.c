#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	pta;
	int	i;
	int	ret;

	va_start(pta, fmt);
	ret = 0;
	i = -1;
	while (fmt[++i])
	{
		if (fmt[i] == '%')
			ret += ft_check_print(fmt, ++i, pta);
		else
			ret += ft_putchar(fmt[i]);
	}
	va_end(pta);
	return (ret);
}
