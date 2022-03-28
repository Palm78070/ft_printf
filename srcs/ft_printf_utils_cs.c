#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (count += write(1, "(null)", 6));
	while (*str)
		count += ft_putchar(*str++);
	return (count);
}
