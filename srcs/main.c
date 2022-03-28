#include "ft_printf.h"
#include "stdio.h"

int	main(void)
{
	//int n2 = 10;
	//int n3 = 100;
	//int n4 = 2000;
	int n = ft_printf("%x\n", LONG_MAX);
	int n2 = printf("%lx\n", LONG_MAX);
	printf("n %i\n", n);
	printf("n2 %i\n", n2);
	//printf("%X\n", 255);
	//ft_printf("%X\n", 255);
	return (0);
}
