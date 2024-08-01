/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:58:01 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:58:01 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putstr_fd - Output a string to a file descriptor.
** char *s	: The string to be output.
** int fd	: The file descriptor on which to write.
**
** DESCRIPTION: This function writes the string 's' to the given file
** descriptor 'fd'. It does not add a newline character.
**
** RETURN: None.
 */

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

/*
int main()
{
	ft_putstr_fd("Hello World...die, die, die...muhahahhaha!!!! ;P", 1);
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_putstr_fd.c ft_strlen.c
