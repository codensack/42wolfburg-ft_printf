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
# include "../lib/libft/include/libft.h"
# include "ft_printf_utils.h"

typedef struct s_printf
{
	char	flag_left_justify;
	char    flag_always_sign;
	char	flag_blank_before_positive_num;
	char	flag_preceed_hex_oct;
	char	flag_fill_zeros_left;
	int		min_width;
	int		precision;

} t_printf;


int	ft_printf(const char *s, ...);
#endif
