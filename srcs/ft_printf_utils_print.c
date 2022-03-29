#include "ft_printf.h"

int	ft_check_print(const char *fmt, int i, va_list pta)
{
	int	ret;

	ret = 0;
	if (fmt[i] == '%')
		ret += ft_putchar('%');
	if (fmt[i] == 'c')
		ret += ft_putchar(va_arg(pta, int));
	if (fmt[i] == 's')
		ret += ft_putstr(va_arg(pta, char *));
	if (fmt[i] == 'p')
		ret += print_address_hex(va_arg(pta, void *));	
	if (fmt[i] == 'd' || fmt[i] == 'i')
		ft_putnbr(va_arg(pta, int), &ret);
	if (fmt[i] == 'u')
		ft_u_putnbr(va_arg(pta, int), &ret);
	if (fmt[i] == 'x' || fmt[i] == 'X')
		ft_print_hex(va_arg(pta, unsigned int), fmt[i], &ret);
	return (ret);
}
