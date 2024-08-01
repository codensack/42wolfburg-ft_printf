/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:57:44 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:57:44 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putchar_fd - Outputs the character 'c' to the given file descriptor.
** char c	: The character to output.
** int fd	: The file descriptor on which to write.
**
** DESCRIPTION: This function writes the character 'c' to the file descriptor
** specified by 'fd'. If writing fails, the function does not perform any
** error handling; it is the caller's responsibility to handle errors
** appropriately.
**
** RETURN: This function does not return a value.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int main()
{
	char	c = 'H';
	int		fd = 1;
	ft_putchar_fd(c, fd);
	c = 'a';
	ft_putchar_fd(c, fd);
	c = 'l';
	ft_putchar_fd(c, fd);
	c = 'l';
	ft_putchar_fd(c, fd);
	c = 'o';
	ft_putchar_fd(c, fd);
	c = '\n';
	ft_putchar_fd(c, fd);
	c = 'T';
	ft_putchar_fd(c, fd);
	c = 'o';
	ft_putchar_fd(c, fd);
	c = 'm';
	ft_putchar_fd(c, fd);
	c = '\n';
	ft_putchar_fd(c, fd);
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_putchar_fd.c
