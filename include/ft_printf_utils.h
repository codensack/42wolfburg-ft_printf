/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:34:31 by tmasur            #+#    #+#             */
/*   Updated: 2022/02/03 12:57:56 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

int	ft_print_str(char *s, int fd);
int	ft_print_address(unsigned long long int n, int fd, int prefix);
int	ft_print_uint(unsigned int n, int fd);
#endif
