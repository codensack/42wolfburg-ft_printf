/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:56:43 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:56:43 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isprint - Check if a character is a printable ASCII character (32-126).
** int c	: The character to check.
**
** DESCRIPTION: Determines if the character 'c' is a printable ASCII character,
** which includes characters from space (32) to tilde (126) inclusive.
**
** RETURN: 1 if 'c' is a printable ASCII character, 0 otherwise.
*/

int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}

/*
#include <stdio.h>

int main()
{
	printf("ft_isprint('a'): %d\n", ft_isprint('a'));
	printf("ft_isprint('1'): %d\n", ft_isprint('1'));
	printf("ft_isprint('_'): %d\n", ft_isprint('_'));
	printf("ft_isprint('?'): %d\n", ft_isprint('?'));
	printf("ft_isprint('-'): %d\n", ft_isprint('-'));
	printf("ft_isprint(0): %d\n", ft_isprint(0));
	printf("ft_isprint(25): %d\n", ft_isprint(25));
	printf("ft_isprint(128): %d\n", ft_isprint(128));
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_isprint.c
