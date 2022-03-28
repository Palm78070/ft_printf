#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <limits.h>

typedef struct	s_print
{
	va_list	args;
	int	zero;
	int	sign;
	int	precision;
	int	width;
	int	hash;
	int	space;
	int	ret_len;
}	f_print;

int	ft_putchar(int c);
int	ft_putstr(char *str);

void	ft_putnbr(int n, int *count);
void	ft_u_putnbr(unsigned int n, int *count);

void	ft_print_hex(uintptr_t n, char c, int *count);
int	print_address_hex(void *ptr);

int     ft_printf(const char *fmt, ...);

#endif 
