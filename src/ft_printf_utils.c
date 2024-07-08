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

int	ft_print_str(char *s, int fd)
{
	int	len;

	if (!s)
		return (ft_print_str("(null)", 1));
	len = ft_strlen(s);
	ft_putstr_fd(s, fd);
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
