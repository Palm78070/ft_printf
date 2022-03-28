#include "ft_printf.h"

void	ft_print_hex(uintptr_t n, char c, int *count)
{
	int	mod;

	if (c != 'p')
		n = (unsigned int)n;
	if (n >= 16)
		ft_print_hex((n / 16), c, count);
	mod = n % 16;
	if (mod >= 0 && mod < 10)
		*count += ft_putchar(mod + '0');
	else
	{
		if (c == 'X')
			*count += ft_putchar(('A' - 10) + mod);
		else
			*count += ft_putchar(('a' - 10) + mod);
	}
}

int	print_address_hex(void *ptr)
{
	int	count;
	uintptr_t	addrs_dec;
	
	count = ft_putstr("0x");
	addrs_dec = (uintptr_t)ptr;
	ft_print_hex(addrs_dec, 'p', &count);
	return (count);
}
