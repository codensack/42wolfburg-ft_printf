
#include <stdio.h>
#include "../include/ft_printf.h"

void	ft_init_specs(t_format_spec *spec)
{
	spec->print_percent = 0;
	spec->flag_left_justify = 0;
	spec->flag_always_sign = 0;
	spec->flag_blank_before_positive_num = 0;
	spec->flag_indicate_hex_oct = 0;
	spec->flag_fill_zeros_left = 0;
	spec->min_width = 0;
	spec->max_length = 0;
	spec->specifier = 0;
}

void	ft_parse_spec(char **str, t_format_spec *spec)
{
	(*str)++;
	ft_init_specs(spec);
	if (**str == '%')
	{
		spec->print_percent = 1;
		return ;
	}
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
	if (**str == 'i' || **str == 'd' || **str == 'u' || **str == 'x' || **str == 'X' || **str == 'c' || **str == 's' || **str == 'p')
		spec->specifier = **str;
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
			printf("Print percent: %d\n", spec->print_percent);
			printf("Flag left justify: %d\n", spec->flag_left_justify);
			printf("Flag always sign: %d\n", spec->flag_always_sign);
			printf("Blank before pos-num: %d\n", spec->flag_blank_before_positive_num);
			printf("Indicate Hex/Oct: %d\n", spec->flag_indicate_hex_oct);
			printf("Fill zeros left: %d\n", spec->flag_fill_zeros_left);
			printf("Min width: %d\n", spec->min_width);
			printf("Length: %d\n", spec->max_length);
			printf("Specifier: %c\n", spec->specifier);
			printf("--------------------------------------\n");
		}
		*test++;
	}
	return (0);
}