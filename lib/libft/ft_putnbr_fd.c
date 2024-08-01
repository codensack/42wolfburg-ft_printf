/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:57:55 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:57:55 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putnbr_fd - Output an integer to a file descriptor.
** int n	: The integer to be output.
** int fd	: The file descriptor on which to write.
**
** DESCRIPTION: This function writes the integer 'n' to the given file
** descriptor 'fd'.
**
** RETURN: None.
**/

void	ft_putnbr_fd(int n, int fd)
{
	long	r;

	r = n;
	if (r < 0)
	{
		ft_putchar_fd('-', fd);
		r = -r;
	}
	if (r >= 10)
		ft_putnbr_fd(r / 10, fd);
	ft_putchar_fd(r % 10 + '0', fd);
}

/*
int main()
{
	ft_putnbr_fd(-24, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-2147483648 , 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(102389, 1);
}
*/

// gcc -Werror -Wall -Wextra ft_putnbr_fd.c ft_putchar_fd.c
