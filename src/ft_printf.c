#include "../include/ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int	len;
	int	fd;
	va_list	vargs;

	len = 0;
	fd = 1;
	va_start(vargs, s);
	while (*s)
	{
		if (*s == '%')
		{
			len += ft_print_arg(vargs, *(++s), fd);
			s++;
		}
		else
			len += ft_print_char(*(s++), fd);
	}
	va_end(vargs);
	return (len);
}

int	ft_print_arg(va_list args, char c, int fd)
{
	if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(args, int), fd));
	else if (c == 'u')
		return (ft_print_uint(va_arg(args, unsigned int), fd));
	else if (c == 'x')
		return (ft_print_hex(va_arg(args, int), fd, 0));
	else if (c == 'X')
		return (ft_print_hex(va_arg(args, int), fd, 1));
	else if (c == 'c')
		return (ft_print_char(va_arg(args, int), fd));
	else if (c == 's')
		return (ft_print_str(va_arg(args, char *), fd));
	else if (c == 'p')
		return (ft_print_address(va_arg(args, unsigned long long int), fd, 1));
	else if (c == '%')
		return (ft_print_char('%', fd));
	return (-1);
}
