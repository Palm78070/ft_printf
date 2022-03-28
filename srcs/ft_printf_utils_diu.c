#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		*count += ft_putstr("-2147483648");
		return ;
	}
	/*if (n == 9223372036854775807LL)
	{
		*count += ft_putstr("9223372036854775807");
		return ;
	}*/
	if (n < 0)
	{
		*count += ft_putchar('-');
		ft_putnbr(-n, count);		
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, count);
		*count += ft_putchar(n % 10 + '0');
	}
	else
		*count += ft_putchar(n + '0');
}

void	ft_u_putnbr(unsigned int n, int *count)
{
	if (n == 4294967295)
	{	
		*count += ft_putstr("4294967295");
		return ;
	}
	if (n < 0)
	{
		*count += ft_putchar('-');
		ft_putnbr(UINT_MAX + n + 1, count);		
	}
	if (n > 9)
	{
		ft_u_putnbr(n / 10, count);
		*count += ft_putchar((n % 10) + '0');
	}
	else
		*count += ft_putchar(n + '0');	
}
