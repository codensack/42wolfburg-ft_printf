/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 00:01:30 by tmasur            #+#    #+#             */
/*   Updated: 2022/02/03 12:58:23 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../lib/libft/libft.h"

typedef struct s_format_spec
{
	int		print_left;
	int		always_sign;
	int		space_before_positive_num;
	int		indicate_hex_oct;
	int		fill_zeros_left;
	int		min_space_used;
	int		max_length_param; 
	char	type;
} t_format_spec;

// ft_printf.c
int	ft_printf(char *s, ...);
int	ft_print_arg(va_list args, t_format_spec *spec, int fd);
// ft_printf_utils_numbers.c
int	ft_print_int(int n, int fd);
int	ft_print_uint(unsigned int n, int fd);
int	ft_print_hex(int n, int fd, int is_uppercase);
int	ft_print_address(unsigned long long int n, int fd, int prefix);
// ft_printf_utils_alpha.c
int	ft_print_char(int c, int fd);
int	ft_print_str(char *s, int fd);
#endif
