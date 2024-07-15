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
# include "../lib/school42-libft2024/libft.h"
# include "ft_printf_utils.h"

typedef struct s_format_spec
{
	int		flag_left_justify;
	int		flag_always_sign;
	int		flag_blank_before_positive_num;
	int		flag_indicate_hex_oct;
	int		flag_fill_zeros_left;
	int		min_width;	// min space used
	int		max_length; // precision and string-len printed
	char	type;
} t_format_spec;

int	ft_printf(const char *s, ...);
#endif
