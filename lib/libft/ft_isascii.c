/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:56:29 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:56:29 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isascii - Check if a character is a valid ASCII character (0-127).
** int c	: The character to check.
**
** DESCRIPTION: Determines if the character 'c' is within the ASCII range
** (0-127).
**
** RETURN: 1 if 'c' is an ASCII character, 0 otherwise.
*/

int	ft_isascii(int c)
{
	return (c >= '\0' && c <= '~' + 1);
}

/*
#include <stdio.h>

int main()
{
	printf("ft_isascii('a'): %d\n", ft_isascii('a'));
	printf("ft_isascii('1'): %d\n", ft_isascii('1'));
	printf("ft_isascii('_'): %d\n", ft_isascii('_'));
	printf("ft_isascii('?'): %d\n", ft_isascii('?'));
	printf("ft_isascii('-'): %d\n", ft_isascii('-'));
	printf("ft_isascii(0): %d\n", ft_isascii(0));
	printf("ft_isascii(128): %d\n", ft_isascii(128));
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_isascii.c
