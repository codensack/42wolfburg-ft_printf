
#include <stdio.h>
#include "../include/ft_printf.h"

int	ft_print_address(unsigned long long int n, int fd, int prefix)
{
	int	len;

	if (!n)
		return (ft_print_str("(nil)", 1));
	len = 1;
	if (prefix)
		len += ft_print_str("0x", 1);
	if (n > 15)
		len += ft_print_address(n / 16, fd, 0);
	ft_putchar_fd("0123456789abcdef"[n % 16], fd);
	return (len);
}

int	ft_print_uint(unsigned int n, int fd)
{
	int		len;

	len = 1;
	if (n >= 10)
	{
		len += ft_print_uint(n / 10, fd);
	}
	ft_putchar_fd(n % 10 + '0', fd);
	return (len);
}

static int	ft_print_char(int c, int fd)
{
	ft_putchar_fd((char)c, fd);
	return (1);
}

int	ft_print_str(char *s, int fd)
{
	int	len;

	if (!s)
		return (ft_print_str("(null)", 1));
	len = ft_strlen(s);
	ft_putstr_fd(s, fd);
	return (len);
}

#include <stdio.h>

int	ft_print_str_with_flags(char *s, t_format_spec *spec, int fd)
{
	int	len;

	// printf("Das hier ist der übergebene String: %s\n", s);
	if (!s)
		return (ft_print_str("(null)", 1));
	len = ft_strlen(s);
	// printf("Ist flag_print_left set: %d\n", spec->flag_print_left);
	if (spec->flag_print_left)
	{
		ft_putstr_fd(s, fd);
		if (spec->min_width > len)
		{
			while (len <= spec->min_width)
			{
				write(1, " ", 1);
				len++;
			}
		}
	}
	else
	{
		if (spec->min_width > len)
		{
			while (len <= spec->min_width)
			{
				write(1, " ", 1);
				len++;
			}
		}
		ft_putstr_fd(s, fd);
	}
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

void	ft_init_specs(t_format_spec *spec)
{
	spec->flag_print_left = 0;
	spec->flag_always_sign = 0;
	spec->flag_blank_before_positive_num = 0;
	spec->flag_indicate_hex_oct = 0;
	spec->flag_fill_zeros_left = 0;
	spec->min_width = 0;
	spec->max_length = 0;
	spec->type = 0;
}

void	ft_parse_spec(char **str, t_format_spec *spec)
{
	(*str)++;
	ft_init_specs(spec);
	while (**str == '-' || **str == '+' || **str == ' ' || **str == '0' || **str == '#')
	{
        if (**str == '-')
			spec->flag_print_left = 1;
        else if (**str == '+')
			spec->flag_always_sign = 1;
        else if (**str == ' ')
			spec->flag_blank_before_positive_num = 1;
        else if (**str == '#')
			spec->flag_indicate_hex_oct = 1;
        else if (**str == '0')
			spec->flag_fill_zeros_left = 1;
        (*str)++;
    }
	if (ft_isdigit(**str))
		spec->min_width = ft_atoi(*str);
	while (ft_isdigit(**str))
        (*str)++;
	if (**str == '.')
	{
        (*str)++;
        if (ft_isdigit(**str))
            spec->max_length = ft_atoi(*str);
    }
	while (ft_isdigit(**str))
        (*str)++;
	if (**str == 'i' || **str == 'd' || **str == 'u' || **str == 'x' || **str == 'X' || **str == 'c' || **str == 's' || **str == 'p' || **str == '%')
		spec->type = **str;
}

int	ft_print_arg(va_list args, t_format_spec *spec, int fd)
{
	if (spec->type == 'd' || spec->type == 'i')
		return (ft_print_int(va_arg(args, int), fd));
	else if (spec->type == 'u')
		return (ft_print_uint(va_arg(args, unsigned int), fd));
	else if (spec->type == 'x')
		return (ft_print_hex(va_arg(args, int), fd, 0));
	else if (spec->type == 'X')
		return (ft_print_hex(va_arg(args, int), fd, 1));
	else if (spec->type == 'c')
		return (ft_print_char(va_arg(args, int), fd));
	else if (spec->type == 's')
		// return (ft_print_str(va_arg(args, char *), fd));
		return (ft_print_str_with_flags(va_arg(args, char *), spec, fd));
	else if (spec->type == 'p')
		return (ft_print_address(va_arg(args, unsigned long long int), fd, 1));
	else if (spec->type == '%') 
		return (ft_print_char('%', fd));
	return (-1);
}

int	ft_printf(char *s, ...)
{
	int	len;
	int	fd;
	va_list	vargs;
	t_format_spec *spec;

	spec = malloc(sizeof(t_format_spec));
	len = 0;
	fd = 1;
	va_start(vargs, s);
	while (*s)
	{
		if (*s == '%')
		{
			ft_parse_spec(&s, spec);
			len += ft_print_arg(vargs, spec, fd);
			s++;
		}
		else
			len += ft_print_char(*(s++), fd);
	}
	va_end(vargs);
	free(spec);
	return (len);
}

int	main(void)
{
	ft_printf("Das hier ist ein %-10.2s, haha %%, das geht!\n", "HAHA");
	ft_printf("Das hier ist ein %10.2s, haha %%, das geht!\n", "HAHA");
	return (0);
}