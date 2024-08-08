#include <stdio.h>
#include "../include/ft_printf.h"

void	ft_print_whitespaces(int len, int space, int fd)
{
	while (len < space)
	{
		write(fd, " ", 1);
		len++;
	}
}

int	ft_print_int(int n, int fd)
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

int	ft_print_hex(int n, int fd, int is_uppercase)
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

int	ft_print_char_with_flags(int c, t_format_spec *spec, int fd)
{
	int	len;

	len = 0;
	if ((spec->min_space_used > 1) && !(spec->print_left))
		ft_print_whitespaces(len, (spec->min_space_used - 1), fd);
	len += write(1, &c, 1);
	if ((spec->min_space_used > 1) && spec->print_left)
		ft_print_whitespaces(len, (spec->min_space_used - 1), fd);
	return (len);
}

void	ft_print_left(char *s, t_format_spec *spec, int len, int fd)
{
		ft_putstr_fd(s, fd);
		if (spec->min_space_used > len)
			ft_print_whitespaces(len, (spec->min_space_used), fd);
}

void	ft_print_right(char *s, t_format_spec *spec, int len, int fd)
{
		if (spec->min_space_used > len)
			ft_print_whitespaces(len, (spec->min_space_used), fd);
		ft_putstr_fd(s, fd);
}

int	ft_print_str_with_flags(char *s, t_format_spec *spec, int fd)
{
	int		len;
	char	*str;

	if (!s)
		return (ft_print_str("(null)", 1));
	len = ft_strlen(s);
	if (spec->max_length_param && spec->max_length_param < len)
		len = spec->max_length_param;
	str = ft_substr(s, 0, len);
	if (!str)
		return (0);
	if (spec->print_left)
		ft_print_left(str, spec, len, fd);
	else
		ft_print_right(str, spec, len, fd);
	free(str);
	return (len);
}

void	ft_init_specs(t_format_spec *spec)
{
	spec->print_left = 0;
	spec->always_sign = 0;
	spec->space_before_positive_num = 0;
	spec->indicate_hex_oct = 0;
	spec->fill_zeros_left = 0;
	spec->min_space_used = 0;
	spec->max_length_param = 0;
	spec->type = 0;
}

void	ft_parse_spec(char **str, t_format_spec *spec)
{
	(*str)++;
	ft_init_specs(spec);
	while (**str == '-' || **str == '+' || **str == ' ' || **str == '0' || **str == '#')
	{
        if (**str == '-')
			spec->print_left = 1;
        else if (**str == '+')
			spec->always_sign = 1;
        else if (**str == ' ')
			spec->space_before_positive_num = 1;
        else if (**str == '#')
			spec->indicate_hex_oct = 1;
        else if (**str == '0')
			spec->fill_zeros_left = 1;
        (*str)++;
    }
	if (ft_isdigit(**str))
		spec->min_space_used = ft_atoi(*str);
	while (ft_isdigit(**str))
        (*str)++;
	if (**str == '.')
	{
        (*str)++;
        if (ft_isdigit(**str))
            spec->max_length_param = ft_atoi(*str);
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
		return (ft_print_char_with_flags(va_arg(args, int), spec, fd));
	else if (spec->type == 's')
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
	// ft_printf("Kannst du das %c%c%-10c", 'a', 'b', 'c');
	// printf("Strings:\n");	
	// printf("1String -5.2\t: [%-5.2s]\n", "halloechen");
	// printf("7String -15\t: [%-15s]\n", "halloechen");
	// ft_printf("7ftString -15\t: [%-15s]\n", "halloechen");
	// printf("2String -5.6\t: [%-5.6s]\n", "halloechen");
	// ft_printf("2ftString -5.6\t: [%-5.6s]\n", "halloechen");
	// printf("3String -5.6 ha\t: [%-5.6s]\n", "ha");
	// ft_printf("3ftString -5.6 ha\t: [%-5.6s]\n", "ha");
	// printf("5String -5\t: [%-5s]\n", "halloechen");
	// ft_printf("5ftString -5\t: [%-5s]\n", "halloechen");
	// printf("4String 5.6 ha\t: [%5.6s]\n", "ha");
	// ft_printf("4ftString 5.6 ha\t: [%5.6s]\n", "ha");
	// printf("6String 5.2\t: [%5.2s]\n", "halloechen");
	// ft_printf("6ftString 5.2\t: [%5.2s]\n", "halloechen");
	// printf("8String 15\t: [%15s]\n", "halloechen");
	// ft_printf("8ftString 15\t: [%15s]\n", "halloechen");
	// printf("9String 20.5\t: [%20.5s]\n", "halloechen");
	// ft_printf("9ftString 20.5\t: [%20.5s]\n", "halloechen");
	// printf("aString 5.5\t: [%5.5s]\n", "halloechen");
	// ft_printf("aftString 5.5\t: [%5.5s]\n", "halloechen");
	// printf("bString 5\t: [%5s]\n", "halloechen");
	// ft_printf("bftString 5\t: [%5s]\n", "halloechen");
	// printf("Int\n");
	// printf("1Int -11.5\t: [%-11.5i]\n", 11);
	// printf("1Int -11.2\t: [%-11.2i]\n", 11);
	// printf("1Int -11.2\t: [%-11.2i]\n", -11);
	// printf("1Int -11.1\t: [%-11.1i]\n", 11);
	// printf("1Int -11.1\t: [%-11.1i]\n", -11);
	// printf("1Int -11.1\t: [%-11.1i]\n", -11);
	// printf("2Int +-11.5\t: [% +-11.5i]\n", 11);
	// printf("3Int \' \'-11.5\t: [% -11.5i]\n", 11);
	// printf("3Int n\' \'-11.11\t: [% -11.11i]\n", -11);
	// printf("3Int n\' \'-11.5\t: [% -11.5i]\n", -11);
	// printf("4Int \' \'-11\t: [% -11i]\n", 11);
	// printf("5Int 011\t: [%011i]\n", 11);
	// printf("5Int 011\t: [%011i]\n", -11);
	// printf("5Int 011.5\t: [%011.5i]\n", 11);
	// printf("5Int 011.11\t: [%011.11i]\n", 11);
	// printf("51Int 11\t: [%11i]\n", 11);
	// printf("52Int 11\t: [%11i]\n", -11);
	// printf("6Int -11\t: [%-11i]\n", 11);
	// printf("61Int -11\t: [%-11i]\n", -11);
	// printf("7Int -11.5\t: [%-11.5i]\n", -11);
	// printf("71Int 11.5\t: [%11.5i]\n", -11);
	// printf("8Int +-11.5\t: [%+-11.5i]\n", -11);
	// printf("9Int \' \'-11.5\t: [% -11.5i]\n", -11);
	// printf("aInt -5.15\t: [%-5.15i]\n", 11);
	// printf("bInt +-5.15\t: [%+-5.15i]\n", 11);
	// printf("cInt \' \' -5.15\t: [% -5.15i]\n", 11);
	// printf("dInt \' \' -5.15\t: [% -5.15i]\n", -11);
	// printf("eInt \' \' 5.15\t: [% 5.15i]\n", 11);
	// printf("eInt \' \' 5.5\t: [% 5.5i]\n", 11);
	// printf("eInt \' \' 5.5\t: [% 5.2i]\n", 11111);
	// printf("\nDez\n");
	// printf("1Dez -11.5\t: [%-11.5d]\n", 11);
	// printf("1Dez -11.2\t: [%-11.2d]\n", 11);
	// printf("1Dez -11.2\t: [%-11.2d]\n", -11);
	// printf("1Dez -11.1\t: [%-11.1d]\n", 11);
	// printf("1Dez -11.1\t: [%-11.1d]\n", -11);
	// printf("2Dez +-11.5\t: [%+-11.5d]\n", 11);
	// printf("3Dez \' \'-11.5\t: [% -11.5d]\n", 11);
	// printf("3Dez \' \'-11.5\t: [% -11.5d]\n", -11);
	// printf("4Dez \' \'-11\t: [% -11d]\n", 11);
	// printf("5Dez 011\t: [%011d]\n", 11);
	// printf("51Dez 11\t: [%11d]\n", 11);
	// printf("52Dez 11\t: [%11d]\n", -11);
	// printf("6Dez -11\t: [%-11d]\n", 11);
	// printf("61Dez -11\t: [%-11d]\n", -11);
	// printf("7Dez -11.5\t: [%-11.5d]\n", -11);
	// printf("71Dez 11.5\t: [%11.5d]\n", -11);
	// printf("8Dez +-11.5\t: [%+-11.5d]\n", -11);
	// printf("9Dez \' \'-11.5\t: [% -11.5d]\n", -11);
	// printf("aDez -5.15\t: [%-5.15d]\n", 11);
	// printf("bDez +-5.15\t: [%+-5.15d]\n", 11);
	// printf("cDez \' \' -5.15\t: [% -5.15d]\n", 11);
	// printf("dDez \' \' -5.15\t: [% -5.15d]\n", -11);
	// printf("eDez \' \' 5.15\t: [% 5.15d]\n", 11);
	// printf("fDez 2\t\t: [%2d]\n", 11);
	// printf("gDez 1\t\t: [%1d]\n", 11);
	// printf("hDez \' \' 2\t: [% 2d]\n", 11);
	// printf("iDez \' \' 2\t: [% 2d]\n", -11);
	// printf("\nDez 0\n");
	// printf("1Dez 0 -11.5\t: [%-11.5d]\n", 0);
	// printf("1Dez 0 -11.2\t: [%-11.2d]\n", 0);
	// printf("1Dez 0 -11.1\t: [%-11.1d]\n", 0);
	// printf("2Dez 0 +-11.5\t: [%+-11.5d]\n", 0);
	// printf("3Dez 0 \' \'-11.5\t: [% -11.5d]\n", 0);
	// printf("4Dez 0 \' \'-11\t: [% -11d]\n", 0);
	// printf("5Dez 0 011\t: [%011d]\n", 0);
	// printf("51Dez 0 11\t: [%11d]\n", 0);
	// printf("6Dez 0 -11\t: [%-11d]\n", 0);
	// printf("61Dez 0 -11\t: [%-11d]\n", 0);
	// printf("7Dez 0 -11.5\t: [%-11.5d]\n", 0);
	// printf("71Dez 0 11.5\t: [%11.5d]\n", 0);
	// printf("8Dez 0 +-11.5\t: [%+-11.5d]\n", 0);
	// printf("8Dez 0 +11.5\t: [%+11.5d]\n", 0);
	// printf("9Dez 0 \' \'-11.5\t: [% -11.5d]\n", 0);
	// printf("aDez 0 -5.15\t: [%-5.15d]\n", 0);
	// printf("bDez 0 +-5.15\t: [%+-5.15d]\n", 0);
	// printf("bDez 0 +5.15\t: [%+5.15d]\n", 0);
	// printf("cDez 0 \' \' -5.15\t: [% -5.15d]\n", 0);
	// printf("dDez 0 \' \' -5.15\t: [% -5.15d]\n", 0);
	// printf("eDez 0 \' \' 5.15\t: [% 5.15d]\n", 0);
	// printf("fDez 0 2\t\t: [%2d]\n", 0);
	// printf("gDez 0 1\t\t: [%1d]\n", 0);
	// printf("hDez 0 \' \' 2\t: [% 2d]\n", 0);
	// printf("iDez 0 \' \' 2\t: [% 2d]\n", 0);
	// return (0);
}
