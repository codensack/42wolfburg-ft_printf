/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:57:49 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:57:49 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putendl_fd - Output a string to a file descriptor, followed by a newline.
** char *s	: The string to be output.
** int fd	: The file descriptor on which to write.
**
** DESCRIPTION: This function writes the string 's' to the given file
** descriptor 'fd', followed by a newline character.
**
** RETURN: None
*/

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*
int main()
{
	ft_putendl_fd("Hi, how are you?", 1);
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c
