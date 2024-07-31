/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 03:15:33 by tmasur            #+#    #+#             */
/*   Updated: 2022/02/16 18:39:00 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_char(int c, int fd)
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
