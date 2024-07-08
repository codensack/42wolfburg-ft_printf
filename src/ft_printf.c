#include "../include/ft_printf.h"

static int	ft_print_arg(va_list args, char c, int fd);
static int	ft_print_int(int n, int fd);
static int	ft_print_hex(int n, int fd, int is_uppercase);
static int	ft_print_char(int c, int fd);

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

static int	ft_print_arg(va_list args, char c, int fd)
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

static int	ft_print_int(int n, int fd)
{
	int	tmp;
	int	len;

	tmp = n;
	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	ft_putnbr_fd(tmp, fd);
	return (len);
}

static int	ft_print_hex(int n, int fd, int is_uppercase)
{
	int				len;
	unsigned int	nu;

	nu = (unsigned int)n;
	len = 1;
	if (nu > 15)
		len += ft_print_hex(nu / 16, fd, is_uppercase);
	if (is_uppercase)
		ft_putchar_fd("0123456789ABCDEF"[nu % 16], fd);
	else
		ft_putchar_fd("0123456789abcdef"[nu % 16], fd);
	return (len);
}

static int	ft_print_char(int c, int fd)
{
	ft_putchar_fd((char)c, fd);
	return (1);
}
