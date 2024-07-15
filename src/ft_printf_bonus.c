
#include <stdio.h>
#include "../include/ft_printf.h"

void	ft_init_specs(t_format_spec *spec)
{
	spec->flag_left_justify = 0;
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
			spec->flag_left_justify = 1;
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

int	ft_printf(const char *s, ...)
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
		return (ft_print_str(va_arg(args, char *), fd));
	else if (spec->type == 'p')
		return (ft_print_address(va_arg(args, unsigned long long int), fd, 1));
	else if (spec->type == '%')
		return (ft_print_char('%', fd));
	return (-1);
}

int	main(void)
{
	char 	*test = "Das hier ist ein %10.02s, haha %%, das geht % -0+0#05.6p";

	t_format_spec *spec;

	spec = malloc(sizeof(t_format_spec));
	while (*test)
	{
		printf("Test: %c\n", *test);
		if (*test == '%')
		{
			ft_parse_spec(&test, spec);
			printf("Flag left justify: %d\n", spec->flag_left_justify);
			printf("Flag always sign: %d\n", spec->flag_always_sign);
			printf("Blank before pos-num: %d\n", spec->flag_blank_before_positive_num);
			printf("Indicate Hex/Oct: %d\n", spec->flag_indicate_hex_oct);
			printf("Fill zeros left: %d\n", spec->flag_fill_zeros_left);
			printf("Min width: %d\n", spec->min_width);
			printf("Length: %d\n", spec->max_length);
			printf("type: %c\n", spec->type);
			printf("--------------------------------------\n");
		}
		*test++;
	}
	return (0);
}